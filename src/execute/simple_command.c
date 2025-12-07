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

void	pipe_io(int in, int out)
{
	if (in)
		dup2(in, STDIN_FILENO);
	if (out)
		dup2(out, STDOUT_FILENO);
}

void	execute_builtin(char **tokens, int has_pipe, int in, int out)
{
	int	len;

	pipe_io(in, out);
	len = len_all(tokens);
	if (len)
	{
		if (equal("echo", *tokens))
			ft_echo_tokens(tokens);
		else if (equal("cd", *tokens))
			ft_cd_tokens(tokens, has_pipe);
		else if (equal("pwd", *tokens))
			ft_pwd_tokens();
		else if (equal("export", *tokens))
			ft_export_tokens(tokens);
		else if (equal("unset", *tokens))
			ft_unset_tokens(tokens);
		else if (equal("env", *tokens))
			ft_env_tokens();
		else if (equal("exit", *tokens))
			ft_exit_tokens(tokens, has_pipe);
	}
}

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
	while (paths && *paths)
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

void	execute_binary(char **tokens, int fds[REDIR_MAX], int in, int out)
{
	char	**env;
	int		cpid;
	int		status;
	char	*e_stat;

	cpid = fork();
	status = 0;
	if (cpid == -1)
		error_handle(0, 0);
	else if (cpid == 0)
	{
		// This sleep is only for debugging
		sleep(5);
		env = ft_getallenv();
		pipe_io(in, out);
		execve(*tokens, tokens, env);
		free_all(env);
		exit(status);
	}
	else
		waitpid(cpid, &status, 0);
	compute_fds(fds, CLOSE);
	e_stat = ft_itoa(status);
	ft_export("?", e_stat);
	free(e_stat);
}

void	execute_simple_command(char **tokens, int has_pipe, int in, int out)
{
	char	dir[PATH_MAX];
	int		fds[REDIR_MAX];

	compute_fds(fds, INITIALIZE);
	redirection(tokens, fds);
	if (!ft_strchr(*tokens, '/'))
	{
		execute_builtin(tokens, has_pipe, in, out);
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
	execute_binary(tokens, fds, in, out);
	free_all(tokens);
}
