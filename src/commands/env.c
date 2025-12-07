/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

int	load_env(char **env)
{
	int	aux;
	int	fd;

	fd = open(FILE_ENV, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	aux = 0;
	while (env && env[aux])
	{
		write(fd, env[aux], len(env[aux]));
		write(fd, "\n", 1);
		aux++;
	}
	close(fd);
	return (1);
}

char	**ft_getallenv(void)
{
	int		fd;
	char	**vars;

	fd = open(FILE_ENV, O_RDONLY);
	if (fd == -1)
		return (NULL);
	vars = read_file(fd, '\n');
	return (vars);
}

int	ft_env(void)
{
	char	**vars;
	char	*exclude;
	int		aux;

	vars = ft_getallenv();
	exclude = append(ft_strdup("?="), 5, ft_getenv("?"));
	aux = 0;
	while (vars && vars[aux])
	{
		if (!equal(exclude, vars[aux]))
			printf("%s\n", vars[aux]);
		aux++;
	}
	free(exclude);
	free_all(vars);
	return (1);
}

int	determine_size(char *var, char *name, int size1)
{
	int	size2;

	size2 = ft_strlen(name);
	while (var[size1] != '=')
		size1++;
	if (size1 > size2)
		return (size1);
	return (size2);
}

char	*ft_getenv(char *name)
{
	char	**vars;
	char	*result;
	int		size;
	int		aux;
	int		index;

	result = NULL;
	index = -1;
	vars = ft_getallenv();
	while (vars && vars[++index])
	{
		aux = 0;
		while (vars[index][aux] != '=')
			aux++;
		size = determine_size(vars[index], name, aux);
		if (equaln(vars[index], name, size))
		{
			result = copy_vec(vars[index] + aux + 1);
			break ;
		}
	}
	free_all(vars);
	return (result);
}
