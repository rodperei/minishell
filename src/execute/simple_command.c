/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:09:50 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/17 17:12:46 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"
#include "../../include/ft_limits.h"
#include <stdlib.h>
#include <unistd.h>

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
			ft_echo(tokens);
		else if (i == 1)
			ft_cd(tokens);
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
}

void	check_path_var(char *cmd, char dir[PATH_MAX])
{
	char	*paths;
	int		i;

	paths = ft_getenv("PATH");
	while (*paths)
	{
		i = -1;
		while (*paths && *paths != ':')
		{
			if (++i >= PATH_MAX - 2 - ft_strlen(cmd))
				error_handle(0, "path too long\n");
			dir[i] = *paths++;
		}
		dir[++i] = '/';
		dir[++i] = '\0';
		ft_strlcat(dir, cmd, ft_strlen(cmd));
		if (!access(dir, F_OK))
			return ;
		if (*paths == ':')
			paths++;
	}
	printf("%s: command not found\n", cmd);
	exit(127);
}

void	execute_simple_command(char **tokens)
{
	char	builtins[7][7];
	char	dir[PATH_MAX];
	char	**env;

	execute_redirs();
	initialize_builtin_matrix(builtins);
	if (!ft_strchr(*tokens, '/'))
	{
		execute_builtin(tokens, builtins);
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
	env = ft_getallenv();
	if (execve(*tokens, tokens, env) == -1)
		error_handle(0, 0);
	exit(EXIT_SUCCESS);
}
