/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:54:58 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/07 18:34:58 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/comands.h"
#include "../include/shell_functions.h"
#include <stdio.h>

void	initialize_env(int argc, char **argv, char **env)
{
	int		i;
	int		j;
	char	key[50];
	char	value[10000];

	load_env(env);
	i = 1;
	while (++i < argc)
	{
		j = 0;
		while (*argv[i] && *argv[i] != '=')
			key[j++] = *(argv[i])++;
		key[j] = '\0';
		(argv[i])++;
		j = 0;
		while (*argv[i])
			value[j++] = *(argv[i])++;
		value[j] = '\0';
		ft_export(key, value);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	**tokens;
	char	*tmp;

	if (argc < 2)
		error_handle(0, "Too few arguments");
	initialize_env(argc, argv, env);
	tmp = ft_strdup(argv[1]);
	tokens = tokenize(tmp);
	tokens = expand(tokens);
	i = 0;
	while (tokens[i])
	{
		printf("%s", tokens[i++]);
		printf(" ");
	}
	free_all(tokens);
}
