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

void	result_path(char *pwd, char *path)
{
	char	**matriz;
	int		aux;
	char	*tem;

	matriz = ft_split(path, '/');
	aux = -1;
	while (len_all(matriz) != ++aux)
	{
		if (equal(matriz[aux], ".") || !ft_strlen(matriz[aux]))
			continue ;
		else if (equal(matriz[aux], ".."))
			up(pwd);
		else
		{
			if (pwd[ft_strlen(pwd) - 1] != '/')
			{
				tem = ft_strjoin(pwd, "/");
				free(pwd);
				pwd = tem;
			}
			tem = ft_strjoin(pwd, matriz[aux]);
			free(pwd);
			pwd = tem;
		}
	}
	if (pwd[ft_strlen(pwd) - 1] == '/' && ft_strlen(pwd) > 1)
		pwd[ft_strlen(pwd) - 1] = '\0';
	free_all(matriz);
}

int	ft_cd(char *path)
{
	char	*pwd;
	DIR		*dir;

	pwd = ft_getenv("PWD");
	if (!pwd)
		error("Error: not exist PWD en env");
	if (!path)
		error("Error: *path is NULL");
	result_path(pwd, path);
	printf("%s \n", pwd);
	dir = opendir(pwd);
	if (!dir)
		error("Error: not exist PATH");
	closedir(dir);
	ft_export("PWD", pwd);
	free(pwd);
	return (0);
}
