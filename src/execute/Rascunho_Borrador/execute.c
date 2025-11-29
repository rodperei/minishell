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
#include "../../../include/limits.h"
#include "../../../include/execute_comands.h"

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
		if (in < 0 || out < 0)
		{
			perror("minishel: ");
			exit(1);
		}
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
		tem = ft_itoa(status);
		ft_export("?", tem);
		free(tem);
	}
	return (status);
}

int	excecute_parse(char **parse)
{
	int	aux;
	int	pipefd[PIPE_MAX][2];

	aux = -1;
	fd1 = 0;
	fd2 = 1;
	while (parse && parse[++aux])
	{
		if (equal("\n", parse[aux]))
			continue ;
			
		printf("[execute] %s\n", parse[aux]);
		//>< >>
		fd1 = open(parse[0]);
		fd2 = open(parse[2]);
		excecute_comand(parse, fd1, fd2);
		// Aqui nós executaríamos as redireções sem problema e os pipes também, 
		// já com tudo controlado e expandido, direto para executar.
	}
	return (0);
}
