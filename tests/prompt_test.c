/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:16:00 by rodperei          #+#    #+#             */
/*   Updated: 2025/09/26 19:20:49 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "../../include/helper_functions.h"

int	main(void)
{
	char	*prompt;
	char	*str;

	while (1)
	{
		prompt = create_prompt();
		str = readline(prompt);
		if (!str)
		{
			printf("EOF reached\n");
			free(prompt);
			rl_clear_history();
			break ;
		}
		printf("readline input: %s\n", str);
		add_history(str);
		free(prompt);
		free(str);
	}
}
