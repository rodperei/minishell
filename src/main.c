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
#include <unistd.h>
#include "../include/comands.h"
#include "../include/shell_functions.h"
#include "../include/signal_minishel.h"
#include "../include/utils.h"
#include "../include/main_utils.h"

void	execute_console(char *str, char **env_save)
{
	pid_t	pid;
	int		status;
	char	**tokens;
	int		has_pipe;

	status = search_pipe(str);
	has_pipe = search_pipe(str);
	verryfi_env_cwd(status, env_save);
	pid = fork();
	if (pid == 0)
	{
		signal_father();
		tokens = tokenize(str);
		tokens = parse(tokens);
		tokens = expand(tokens);
		if (has_pipe)
			compute_pipeline(tokens);
		else
			execute_simple_command(tokens, NOT_PIPE);
	}
	else
		waitpid(pid, &status, 0);
	verryfi_env_cwd(status || has_pipe, env_save);
	ft_export_num("?", WEXITSTATUS(status));
}

int	in_loop(void)
{
	char	*exit_main;

	exit_main = ft_getenv("??");
	if (!exit_main)
		return (1);
	free(exit_main);
	return (0);
}

void	initialize_shell(int *argc, char ***argv, char **env)
{
	(void) *argc;
	(void) *argv;
	signal_main();
	load_env(env);
	valid_env();
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	*prompt;
	char	**env_save;

	initialize_shell(&argc, &argv, env);
	while (in_loop())
	{
		env_save = ft_getallenv();
		prompt = create_prompt();
		str = readline(prompt);
		free(prompt);
		if (!str)
			break ;
		if (ft_strlen(str))
		{
			add_history(str);
			execute_console(str, env_save);
		}
		free_all(env_save);
	}
	rl_clear_history();
	last_exit();
}
