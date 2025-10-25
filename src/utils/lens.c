/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	len(char *str)
{
	int	aux;

	aux = 0;
	while (str && str[aux])
		aux++;
	return (aux);
}

int	len_all(char **str)
{
	int	aux;

	aux = 0;
	while (str && str[aux] && str[aux][0])
		aux++;
	return (aux);
}

int	equal(char *str, char *str1)
{
	int	aux;

	if (!str || !str1)
		return (str == str1);
	aux = 0;
	while (str[aux] && str1[aux])
	{
		if (str[aux] != str1[aux])
			return (0);
		aux++;
	}
	return (str[aux] == str1[aux]);
}

int	equaln(char *str, char *str1, int size)
{
	int	aux;

	if (!str || !str1)
		return (str == str1);
	aux = 0;
	while (str[aux] && str1[aux] && aux < size)
	{
		if (str[aux] != str1[aux])
			return (0);
		aux++;
	}
	return (1);
}
