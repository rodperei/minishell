/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:09:50 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/02 21:26:12 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"
#include "../../include/ft_limits.h"
#include "../../include/shell_functions.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define INITIALIZE 0
#define CLOSE 1

void	initialize_builtin_matrix(char builtins[7][7])
{
	ft_memmove(builtins[0], "echo", ft_strlen("echo") + 1);
	ft_memmove(builtins[1], "cd", ft_strlen("cd") + 1);
	ft_memmove(builtins[2], "pwd", ft_strlen("pwd") + 1);
	ft_memmove(builtins[3], "export", ft_strlen("export") + 1);
	ft_memmove(builtins[4], "unset", ft_strlen("unset") + 1);
	ft_memmove(builtins[5], "env", ft_strlen("env") + 1);
	ft_memmove(builtins[6], "exit", ft_strlen("exit") + 1);
}
/*
void	execute_builtin(char **tokens, char builtins[7][7])
{
	char	i;
	int		cmp;

	i = -1;
	cmp = 1;
	while (++i < 7 && cmp)
		cmp = ft_strncmp(builtins[i], *tokens, ft_strlen(*tokens));
	if (cmp == 0)
	{
		if (i == 0)
			ft_echo_tokens(tokens);
		else if (i == 1)
			ft_cd_tokens(tokens);
		else if (i == 2)
			ft_pwd();
		else if (i == 3)
			ft_export(tokens);
		else if (i == 4)
			ft_unset(tokens);
		else if (i == 5)
			ft_env();
		else if (i == 6)
			ft_exit();
	}
	exit(EXIT_SUCCESS)
}*/

void	build_cmd_path(char *cmd, char dir[PATH_MAX], char **paths)
{
	int	i;

	i = -1;
	while (**paths && **paths != ':')
	{
		if (++i >= PATH_MAX - 2 - (int) ft_strlen(cmd))
			error_handle(0, "path too long\n");
		dir[i] = *(*paths)++;
	}
	dir[++i] = '/';
	dir[++i] = '\0';
	ft_strlcat(dir, cmd, PATH_MAX);
}

void	check_path_var(char *cmd, char dir[PATH_MAX])
{
	char	*paths;
	char	*tmp;

	paths = ft_getenv("PATH");
	tmp = paths;
	while (*paths)
	{
		build_cmd_path(cmd, dir, &paths);
		if (!access(dir, F_OK))
		{
			free(tmp);
			return ;
		}
		if (*paths == ':')
			paths++;
	}
	printf("%s: command not found\n", cmd);
	free(tmp);
	exit(127);
}

void	compute_fds(int fds[REDIR_MAX], char mode)
{
	int	i;

	if (mode == INITIALIZE)
	{
		i = -1;
		while (++i < REDIR_MAX)
			fds[i] = -2;
	}
	else
	{
		i = 0;
		while (fds[i] != -2 && i < REDIR_MAX)
			close(fds[i++]);
	}
}

void	execute_binary(char **tokens, int fds[REDIR_MAX])
{
	char	**env;
	int		cpid;
	int		status;

	env = ft_getallenv();
	cpid = fork();
	status = 0;
	if (cpid == -1)
		error_handle(0, 0);
	else if (cpid == 0)
	{
		// This sleep is only for debugging
		//sleep(8);
		execve(*tokens, tokens, env);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(cpid, &status, 0);
	free_all(env);
	free_all(tokens);
	compute_fds(fds, CLOSE);
	ft_export("?", ft_itoa(status));
}

void	execute_simple_command(char **tokens)
{
	char	builtins[7][7];
	char	dir[PATH_MAX];
	int		fds[REDIR_MAX];

	compute_fds(fds, INITIALIZE);
	redirection(tokens, fds);
	initialize_builtin_matrix(builtins);
	if (!ft_strchr(*tokens, '/'))
	{
		//execute_builtin(tokens, builtins);
		check_path_var(*tokens, dir);
		free(*tokens);
		*tokens = ft_strdup(dir);
	}
	else
	{
		if (access(*tokens, F_OK))
		{
			perror("minishell: ");
			exit(127);
		}
	}
	execute_binary(tokens, fds);
}
