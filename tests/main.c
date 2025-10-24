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
#include "../include/utils.h"

int	main(int av, char **ac, char **env)
{
	char	*prompt;
	char	*str;

	load_env(env);
	printf("%d", av);
	printf("%s\n\n", ac[0]);

	while (1)
	{
		prompt = create_prompt();
		str = readline(prompt);
		if (!str || equal(str, "exit"))
			break ;
		printf("readline input: %s\n", str);
		add_history(str);
		free(prompt);
		free(str);
	}

	printf("EOF reached\n");
	rl_clear_history();
	if (str)
		free(str);
	if (prompt)
		free(prompt);
}
