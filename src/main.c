/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:13:34 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/03 21:36:17 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../include/comands.h"
#include "../include/shell_functions.h"
#include "../include/signal_minishel.h"
#include "../include/utils.h"
#include "tokenizer/tokenizer.h"

void	verryfi_env_cwd(int status, char **env_save)
{
	char	*pwd;
	char	**env;

	env = ft_getallenv();
	if ((!env || len_all(env) < 2) && env_save)
		load_env(env_save);
	if (env)
		free_all(env);
	if (status)
		return;
	pwd = ft_getcwd();
	if (!pwd)
		return ;
	chdir(pwd);
	free(pwd);
}

char	*search_pipe(char *str)
{
	char	flg;

	flg = 0;
	while (str && *str)
	{
		compute_flg_mask(*str, &flg);
		if (!flg && ft_strchr("|", *str))
			return (str);
		str++;
	}
	return (0);
}

void	execute_console(char *str, char **env_save)
{
	pid_t	pid;
	int		status;
	char	*e_stat;
	char	**tokens;
	char	*has_pipe;

	status = 0;
	has_pipe = search_pipe(str);
	ft_export("?", "0");
	verryfi_env_cwd(status || has_pipe, env_save);
	pid = fork();
	if (pid == 0)
	{
		// This sleep is only for debugging
		//sleep(5);
		signal_father();
		tokens = tokenize(str);
		tokens = parse(tokens);
		tokens = expand(tokens);
		if (has_pipe)
			compute_pipeline(tokens);
		else
			execute_simple_command(tokens, NOT_PIPE);
		ft_exit(0);
	}
	else
		waitpid(pid, &status, 0);
	verryfi_env_cwd(status || has_pipe, env_save);
	e_stat = ft_itoa(WEXITSTATUS(status));
	ft_export("?", e_stat);
	free(e_stat);
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	*prompt;
	char	**env_save;

	(void) argc;
	(void) argv;
	signal_main();
	load_env(env);
	while (1)
	{
		env_save = ft_getallenv();
		prompt = create_prompt();
		str = readline(prompt);
		free(prompt);
		if (!str)
			break ;
		add_history(str);
		execute_console(str, env_save);
		free_all(env_save);
	}
	free_all(env_save);
	rl_clear_history();
	unlink(FILE_ENV);
}
