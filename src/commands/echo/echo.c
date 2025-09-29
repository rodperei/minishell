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

#include "../../utils/utils.h"
#include "../../../include/comands.h"

int	error(char *str)
{
	printf("%s\n", str);
	exit(127);
}

int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	print_env(char *str)
{
	char	var[1025];
	int		aux;

	str++;
	aux = 0;
	while (str && str[aux] && is_letter(str[aux]))
	{
		var[aux] = str[aux];
		aux++;
	}
	var[aux] = '\0';
	printf("%s", getenv(var));
	return (++aux);
}

void	print_text(char *str)
{
	while (str && *str)
	{
		if (*str == '$')
			str += print_env(str);
		write(1, str, 1);
		str++;
	}
}

int	ft_echo(char **args, char *text)
{
	if (len_all(args) > 1)
		error("unknown arguments");
	if (len_all(args) == 1 && !equal(args[0], "-n"))
		error("unknown arguments diff -n");
	print_text(text);
	if (len_all(args) == 0)
		printf("\n");
	return (0);
}
