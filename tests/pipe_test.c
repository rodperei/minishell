/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:11:13 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/02 23:17:11 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/comands.h"
#include "../include/shell_functions.h"
#include "../include/utils.h"

int	main(int argc, char **argv, char **env)
{
	char **tokens;

	(void) argc;
	load_env(env);
	tokens = tokenize(ft_strdup(argv[1]));
	compute_pipeline(tokens);
	free_all(tokens);
}
