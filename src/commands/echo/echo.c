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

#include "../utils/utils.h"

int	error(char *str)
{
	ft_printf(str);
	ft_printf("\n");
	exit(127);
}

int	echo(char **args, char *text)
{
	if (len_all(args) > 1)
		error("unknown arguments");
	if (len_all(args) == 1 && !equal(args[0], "-n"))
		error("unknown arguments diff -n");
	ft_printf("%s", text);
	if (len_all(args) == 0)
		ft_printf("\n");
	return (0);
}

/*
int	main(int av, char **ac, char **env)
{
	ac++;
	echo(ac, "**----demo----**");
	len_all(env);
	ft_printf("%d", av);
}
*/
