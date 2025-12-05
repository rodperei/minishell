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

void	execute_builtin(char **tokens)
{
	int	len;

	len = len_all(tokens);
	if (len)
	{
		if (!ft_strncmp("echo", *tokens, ft_strlen(*tokens)))
			ft_echo_tokens(tokens);
		else if (!ft_strncmp("cd", *tokens, ft_strlen(*tokens)))
			ft_cd_tokens(tokens);
		else if (!ft_strncmp("pwd", *tokens, ft_strlen(*tokens)))
			ft_pwd();
		else if (!ft_strncmp("export", *tokens, ft_strlen(*tokens)))
			ft_export_tokens(tokens);
		else if (!ft_strncmp("unset", *tokens, ft_strlen(*tokens)))
			ft_unset_tokens(tokens);
		else if (!ft_strncmp("env", *tokens, ft_strlen(*tokens)))
			ft_env();
		else if (!ft_strncmp("exit", *tokens, ft_strlen(*tokens)))
			ft_exit();
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
	char	*e_stat;

	cpid = fork();
	status = 0;
	if (cpid == -1)
		error_handle(0, 0);
	else if (cpid == 0)
	{
		// This sleep is only for debugging
		//sleep(3);
		env = ft_getallenv();
		execve(*tokens, tokens, env);
		free_all(env);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(cpid, &status, 0);
	compute_fds(fds, CLOSE);
	e_stat = ft_itoa(status);
	ft_export("?", e_stat);
	free(e_stat);
}

void	execute_simple_command(char **tokens)
{
	char	dir[PATH_MAX];
	int		fds[REDIR_MAX];

	compute_fds(fds, INITIALIZE);
	redirection(tokens, fds);
	if (!ft_strchr(*tokens, '/'))
	{
		execute_builtin(tokens);
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
	free_all(tokens);
}
