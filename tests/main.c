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
#include "../include/helper_functions.h"
#include "../include/parse.h"
#include "../include/utils.h"
#include "../include/redirections.h"

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

int	main(int av, char **ac, char **env)
{
	char	*prompt;
	char	*str;
	char	**tokens;
	char	**parses;
	char	**pre_exec;

	load_env(env);
	printf("%d %s\n\n", av, ac[0]);
	parses = NULL;
	pre_exec = NULL;
	while (1)
	{
		prompt = create_prompt();
		str = readline(prompt);
		if (!str || equal(str, "exit"))
			break ;
		add_history(str);
		tokens = tokenize(str);
		if (tokens)
			parses = parse(tokens);
		if (parses)
			pre_exec = redirection(&parses);
		free_vars(&prompt, NULL, &tokens, &parses);
	}
	rl_clear_history();
	free_vars(&prompt, &str, NULL, NULL);
}
