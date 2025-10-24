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

#include "../../../include/utils.h"
#include "../../../include/comands.h"
#include <dirent.h>

void	up(char *pwd)
{
	int		aux;
	int		last;

	aux = 0;
	last = 0;
	while (pwd && pwd[aux])
	{
		if (pwd[aux] == '/')
			last = aux;
		aux++;
	}
	pwd[last + 1] = '\0';
}

void	result_path(char *pwd, char *path)
{
	char	**matriz;
	int		aux;

	matriz = ft_split(path, '/');
	aux = 0;
	while (len_all(matriz) != aux)
	{
		if (equal(matriz[aux], ".") || !ft_strlen(matriz[aux]))
			continue ;
		else if (equal(matriz[aux], ".."))
			up(pwd);
		else
		{
			append(pwd, ft_strlen(pwd) + 2, "/");
			append(pwd, ft_strlen(pwd) + ft_strlen(matriz[aux]), matriz[aux]);
		}
		aux++;
	}
	if (ft_strlen(pwd))
		pwd[ft_strlen(pwd) - 1] = '\0';
	free_all(matriz);
}

int	ft_cd(char *path)
{
	char	*pwd;
	char	*path_fin;
	DIR		*dir;

	pwd = ft_getenv("PWD");
	if (!pwd)
		error("Error: not exist PWD en env");
	if (!path)
		error("Error: *path is NULL");
	path_fin = ft_strjoin(pwd, "/");
	path_fin = append(path_fin, ft_strlen(path_fin) + ft_strlen(path), path);
	dir = opendir(path_fin);
	if (!dir)
		error("Error: not exist PATH");
	closedir(dir);
	result_path(pwd, path);
	ft_export("PWD", pwd);
	free(pwd);
	return (0);
}
