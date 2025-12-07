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
	int		i;

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
	char	**s_cmd;

	i = count_commands(tokens);
	if (pipe(p_fd) == -1)
		error_handle(0, 0);
	j = 0;
	while (++j <= i)
	{
		s_cmd = choose_tokens(tokens, j);
		cpid = fork();
		if (cpid == -1)
			error_handle(0, 0);
		if (cpid == 0)
		{
			// This sleep is only for debugging
			sleep(5);
			if (j != 0)
				execute_simple_command(s_cmd, HAS_PIPE, 0, p_fd[1]);
			else if (j != i)
				execute_simple_command(s_cmd, HAS_PIPE, p_fd[0], 0);
			else
				execute_simple_command(s_cmd, HAS_PIPE, p_fd[0], p_fd[1]);
			close(p_fd[0]);
			close(p_fd[1]);
			exit(EXIT_SUCCESS);
		}
	}
	close(p_fd[0]);
	close(p_fd[1]);
	free_all(tokens);
}
