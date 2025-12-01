/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:25:51 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/26 20:25:51 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_limits.h"
#include "../../include/utils.h"
#include <sys/wait.h>
#include <unistd.h>

void	create_pipes(char **tokens, int pipefd[PIPE_MAX][2])
{
	int	i;

	i = -1;
	while (++i < PIPE_MAX)
		pipefd[i][0] = -2;
	i = 0;
	while (*tokens)
	{
		if (i >= PIPE_MAX)
			error_handle(0, "Exceeded maximum pipe number");
		if (ft_strncmp(*tokens, "|", ft_strlen(*tokens)))
			if (pipe(pipefd[i++]) == -1)
				error_handle(0, 0);
	}
}

void	compute_pipeline(char **tokens)
{
	int		pipefd[PIPE_MAX][2];
	int		i;
	pid_t	cpid;

	create_pipes(tokens, pipefd);
	|***CONTINUE_HERE!!!***|
		criar lógica de child, tendo em conta as situações de execuçao no inicio meio e fim do pipeline.
	i = -1;
	while (pipefd[++i][0] != -2)
	{
		cpid = fork();
		if (cpid == -1)
			error_handle(0, 0);
		if (cpid == 0 && i == 0)
		{
			close(pipefd[i][0]);

		}
	}
}
