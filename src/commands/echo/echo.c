/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../comands.h"

int	error(char *str)
{
	ft_printf(str);
	ft_printf("\n");
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
	ft_printf("%s", getenv(var));
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

int	echo(char **args, char *text)
{
	if (len_all(args) > 1)
		error("unknown arguments");
	if (len_all(args) == 1 && !equal(args[0], "-n"))
		error("unknown arguments diff -n");
	print_text(text);
	if (len_all(args) == 0)
		ft_printf("\n");
	return (0);
}

/*
int	main(int av, char **ac, char **env)
{
	ac++;
	echo(ac, "**----demo---- $path ** $PATH **");
	len_all(env);
	ft_printf("%d", av);
}
*/
