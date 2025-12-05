/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

void	print_str(char *str)
{
	if (!str)
		return ;
	while (str)
		write(1, str++, 1);
}

int	print_env(char *str)
{
	char	var[1025];
	int		aux;
	char	*var_env;

	str++;
	aux = -1;
	while (str && str[++aux] && str[aux] != ' ')
		var[aux] = str[aux];
	var[aux] = '\0';
	var_env = ft_getenv(var);
	if (var_env)
	{
		print_str(var_env);
		free(var_env);
	}
	return (++aux);
}

void	print_text(char *str)
{
	while (str && *str)
	{
		if (*str == '$')
			str += print_env(str);
		if (*str == 92)
		{
			str++;
			write(1, str, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}

int	ft_echo(char *text, int flag_n)
{
	print_text(text);
	if (!flag_n)
		printf("\n");
	return (0);
}
