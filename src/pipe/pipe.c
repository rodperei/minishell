/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/11/29 17:56:41 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	count_pipe(char **tokens)
{
	int	cant;
	int	i;

	i = -1;
	cant = -1;
	while (tokens && tokens[++i])
		cant += equal("|", tokens[i]);
	cant++;
	if (cant >= PIPE_MAX)
		error_handle(0, "Exceeded pipe maximum limit\n");
	return (cant);
}

char	**comand_index(char **tokens, int index)
{
	int		aux;
	int		init;
	int		end;
	int		comand;
	char	**result;

	aux = -1;
	comand = 0;
	init = -1;
	end = len_all(tokens);
	while (tokens && tokens[++aux])
	{
		if (comand == index && init == -1)
			init = aux;
		if (comand > index)
		{
			end = aux;
			break ;
		}
		if (equal("|", tokens[aux]))
			comand++;
	}
	result = calloc((end - init) + 1, sizeof(char *));
	aux = -1;
	while ((init + (++aux)) != end)
		if (!equal(tokens[init + aux], "|"))
			result[aux] = ft_strdup(tokens[init + aux]);
	return (result);
}

void	await(int pid[PIPE_MAX], int cant_pipe, char **tokens)
{
	int	aux;
	int	status;

	aux = -1;
	free_all(tokens);
	while (++aux <= cant_pipe)
		waitpid(pid[aux], &status, 0);
	ft_exit(aux);
}

void	compute_pipeline(char **tokens)
{
	int		cant_pipe;
	int		p_fd[PIPE_MAX][2];
	int		pid[PIPE_MAX];
	char	**s_cmd;
	int		aux;

	cant_pipe = count_pipe(tokens);
	init_pipe(p_fd, cant_pipe);
	aux = -1;
	while (++aux <= cant_pipe)
	{
		s_cmd = comand_index(tokens, aux);
		pid[aux] = fork();
		if (pid[aux] == 0)
		{
			if (aux == 0)
				pipe_io(0, p_fd[aux][1]);
			else if (aux == cant_pipe)
				pipe_io(p_fd[aux - 1][0], 0);
			else
				pipe_io(p_fd[aux - 1][0], p_fd[aux][1]);
			close_pipe(p_fd, cant_pipe);
			execute_simple_command(s_cmd, HAS_PIPE);
		}
		free_all(s_cmd);
	}
	close_pipe(p_fd, cant_pipe);
	await(pid, cant_pipe, tokens);
}
