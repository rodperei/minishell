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
#include "../../include/shell_functions.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	count_commands(char **tokens)
{
	int	i;

	i = 0;
	while (*tokens)
		if (!ft_strncmp(*tokens++, "|", 2))
			i++;
	i++;
	if (i >= PIPE_MAX)
		error_handle(0, "Exceeded pipe maximum limit\n");
	return (i);
}

char	**alloc_simple_cmd(char **tokens, size_t i)
{
	size_t	size;
	char	**simple_cmd;

	size = 0;
	while (tokens[i] && ft_strncmp(tokens[i], "|", 2))
	{
		size++;
		i++;
	}
	simple_cmd = malloc((size + 1) * sizeof(char *));
	return (simple_cmd);
}

char **choose_tokens(char **tokens, int i)
{
	char	**simple_cmd;
	size_t	j;

	j = 0;
	while (i - 1)
	{
		if (!ft_strncmp(tokens[j], "|", 2))
			i--;
		j++;
	}
	simple_cmd = alloc_simple_cmd(tokens, j);
	i = 0;
	while (tokens[j] && ft_strncmp(tokens[j], "|", 2))
		simple_cmd[i++] = ft_strdup(tokens[j++]);
	simple_cmd[i] = 0;
	return (simple_cmd);
}

void	compute_pipeline(char **tokens)
{
	int		i;
	int		j;
	int		p_fd[2];
	pid_t	cpid;

	i = count_commands(tokens);
	if (pipe(p_fd) == -1)
		error_handle(0, 0);
	j = 0;
	while (++j <= i)
	{
		cpid = fork();
		if (cpid == -1)
			error_handle(0, 0);
		if (cpid == 0)
		{
			// Sleep command only for debugging
			//sleep(15);
			if (j != 0)
				dup2(p_fd[0], STDIN_FILENO);
			else if (j != i)
				dup2(p_fd[1], STDOUT_FILENO);
			execute_simple_command(choose_tokens(tokens, j));
			close(p_fd[0]);
			close(p_fd[1]);
			exit(EXIT_SUCCESS);
		}
	}
	close(p_fd[0]);
	close(p_fd[1]);
}
