/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"
#include <dirent.h>

void	up(char *pwd)
{
	int		aux;
	int		last;

	aux = 0;
	last = -1;
	while (pwd && pwd[aux])
	{
		if (pwd[aux] == '/' && pwd[aux + 1])
			last = aux;
		aux++;
	}
	if (last >= 0)
		pwd[last + 1] = '\0';
}

void	strip_end(char **str)
{
	if ((*str)[ft_strlen(*str) - 1] == '/' && ft_strlen(*str) > 1)
		(*str)[ft_strlen(*str) - 1] = '\0';
}

void	rute_abs(char **pwd, char *path)
{
	free(*pwd);
	*pwd = ft_strdup(path);
	strip_end(pwd);
}

void	result_path(char **pwd, char *path)
{
	char	**matriz;
	char	*tmp;
	int		aux;

	if (path[0] == '/')
		return (rute_abs(pwd, path));
	matriz = ft_split(path, '/');
	aux = -1;
	while (len_all(matriz) != ++aux)
	{
		if (equal(matriz[aux], ".") || !ft_strlen(matriz[aux]))
			continue ;
		else if (equal(matriz[aux], ".."))
			up(*pwd);
		else
		{
			tmp = ft_strjoin(*pwd, "/");
			free(*pwd);
			*pwd = ft_strjoin(tmp, matriz[aux]);
			free(tmp);
		}
	}
	strip_end(pwd);
	free_all(matriz);
}

int	ft_cd(char *path)
{
	char	*pwd;
	DIR		*dir;

	pwd = ft_getenv("PWD");
	if (!pwd)
		error_handle_f(127, "Error: not exist PWD en env\n");
	if (!path)
		error_handle_f(127, "Error: *path is NULL\n");
	result_path(&pwd, path);
	dir = opendir(pwd);
	if (!dir)
		error_handle_f(1, "cd: No such file or directory\n");
	closedir(dir);
	ft_export("PWD", pwd);
	free(pwd);
	return (0);
}
