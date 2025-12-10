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

#include "simple_command.h"
#include <dirent.h>

void	execute_builtin(char **tokens, int has_pipe)
{
	if (equal("echo", *tokens))
		ft_echo_tokens(tokens);
	else if (equal("cd", *tokens))
		ft_cd_tokens(tokens, has_pipe);
	else if (equal("pwd", *tokens))
		ft_pwd_tokens();
	else if (equal("export", *tokens))
		ft_export_tokens(tokens, has_pipe);
	else if (equal("unset", *tokens))
		ft_unset_tokens(tokens, has_pipe);
	else if (equal("env", *tokens))
		ft_env_tokens();
	else if (equal("exit", *tokens))
		ft_exit_tokens(tokens, has_pipe);
}

void	execute_binary(char **tokens)
{
	char	**env;

	env = ft_getallenv();
	execve(tokens[0], tokens, env);
	free_all(tokens);
	free_all(env);
	if (errno == EACCES)
	{
		perror("minishel: ");
		exit(126);
	}
	else if (errno == ENOENT)
	{
		write(2, " command not found", len(" command not found"));
		exit(127);
	}
	printf("errror ---> %d \n", errno);
	error_handle_f(errno, 0);
}

void	is_directory(char **tokens)
{
	DIR	*dir;

	if (!include(*tokens, "/"))
		return ;
	dir = opendir(*tokens);
	if (!dir)
		return ;
	closedir(dir);
	error_handle_f(126, " Is a directory");
}

void	execute_simple_command(char **tokens, int has_pipe)
{
	char	dir[PATH_MAX];
	int		fds[REDIR_MAX];

	while (tokens && *tokens && !len(*tokens))
		tokens++;
	if (!*tokens)
		exit(0);
	is_directory(tokens);
	compute_fds(fds, INITIALIZE);
	tokens = redirection(tokens, fds);
	if (!ft_strchr(*tokens, '/'))
	{
		if (is_builtin(tokens))
			execute_builtin(tokens, has_pipe);
		check_path_var(*tokens, dir);
		free(*tokens);
		*tokens = ft_strdup(dir);
	}
	execute_binary(tokens);
	compute_fds(fds, CLOSE);
	free_all(tokens);
}
