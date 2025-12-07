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
#include <readline/readline.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	char	**tokens;
	char	*str;
	int		status;
	pid_t	cpid;

	(void) argc;
	(void) argv;
	load_env(env);
	while (1)
	{
		str = readline(">");
		if (!str)
			break ;
		cpid = fork();
		if (cpid == 0)
		{
			// Sleep only for debugging
			sleep(5);
			tokens = tokenize(str);
			tokens = parse(tokens);
			compute_pipeline(tokens);
		}
		else
			waitpid(cpid, &status, 0);
	}
	free_all(tokens);
}
