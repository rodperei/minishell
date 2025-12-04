/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/parse.h"
#include "../../../include/comands.h"
#include "../../../include/ft_limits.h"
#include "../../../include/execute_comands.h"
#include "../../include/signal_minishel.h"

int	excecute_comand(char **tokens, int in, int out)
{
	int		pid;
	int		status;
	int		error;
	char	*tem;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		signal_son();
		if (in < 0 || out < 0)
			error_handle(127, "minishel: ");
		if (in)
			dup2(in, STDIN_FILENO);
		if (in)
			close(in);
		if (out)
			dup2(out, STDOUT_FILENO);
		if (out)
			close(out);
		execute_simple_command(tokens);
	}
	else
	{
		waitpid(pid, &status, 0);
		ft_export("?", ft_itoa(status));
	}
	return (status);
}

int	excecute_parse(char **parse)
{
	int	aux;
	int	pipefd[PIPE_MAX][2];

	aux = -1;
	while (parse && parse[++aux])
	{
		if (equal("\n", parse[aux]))
			continue ;
		printf("[execute] %s\n", parse[aux]);
		excecute_comand(parse, parse[0], parse[2]);
	}
	return (0);
}
