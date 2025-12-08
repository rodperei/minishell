/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traductor_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

void	ft_env_tokens(void)
{
	ft_env();
	error_handle(0, 0);
}

int	verify(char *str)
{
	while (str && *str)
	{
		if ((*str < '0' || *str > '9') && (*str != '+'))
		{
			if (*str == '-')
				return (1);
			return (2);
		}
		str++;
	}
	return (0);
}

void	ft_exit_tokens(char **tokens, int has_pipe)
{
	int	len;

	len = len_all(tokens);
	if (len == 1)
		ft_exit(0);
	if (verify(tokens[1]) == 1)
		error_handle(156, "");
	if (verify(tokens[1]) == 2)
		error_handle(2, "exit: numeric argument required");
	if (len > 2)
		error_handle(1, "exit: too many arguments");
	if (!has_pipe)
		ft_exit(ft_atoi(tokens[1]));
}
