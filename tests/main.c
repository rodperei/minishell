/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/comands.h"
#include "../include/shell_functions.h"
#include "../include/parse.h"
#include "../include/utils.h"
//#include "../include/redirections.h"
#include "../include/execute_comands.h"
#include "../include/signal_minishel.h"

void	free_vars(char **v1, char **v2, char ***m1, char ***m2)
{
	if (v1 && (*v1))
	{
		free((*v1));
		(*v1) = NULL;
	}
	if (v2 && (*v2))
	{
		free((*v2));
		(*v2) = NULL;
	}
	if (m1 && (*m1))
	{
		free_all((*m1));
		(*m1) = NULL;
	}
	if (m2 && (*m2))
	{
		free_all((*m2));
		(*m2) = NULL;
	}
}

int	excecute_console(char *str)
{
	int		pid;
	int		status;
	char	**tokens;
	char	**parses;
	char	*tem;

	parses = NULL;
	tokens = NULL;
	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		signal_father();
		tokens = tokenize(str);
		parses = parse(tokens);
		parses = expand(parses);
		//redirection(&parses);
		//excecute_parse(parses);
		free_vars(NULL, NULL, &tokens, &parses);
		exit(0);
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

int	main(int av, char **ac, char **env)
{
	char	*prompt;
	char	*str;
	int		status;

	signal_main();
	load_env(env);
	printf("%d %s\n\n", av, ac[0]);
	while (1)
	{
		prompt = create_prompt();
		str = readline(prompt);
		if (!str || equal(str, "exit"))
			break ;
		add_history(str);
		status = excecute_console(str);
		printf("\n[main] filho termino em: %d\n", status);
		free_vars(&prompt, NULL, NULL, NULL);
	}
	rl_clear_history();
	free_vars(&prompt, &str, NULL, NULL);
}
