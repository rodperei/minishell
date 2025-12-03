/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	cont_words(char *str, char C)
{
	int	cant;
	int	aux;

	cant = 0;
	aux = 0;
	while (str && str[aux])
	{
		while (str[aux] == C)
			aux++;
		if (str[aux] != C && str[aux])
			cant++;
		while (str[aux] != C && str[aux])
			aux++;
	}
    if (cant > 2)
        return (2);
	return (cant);
}

int	cont_letter(char *str, char C)
{
	int	cant;
	int	aux;

	cant = 0;
	aux = 0;
	while (str[aux] && (str[aux] != C || str[aux] == C))
	{
		cant++;
		aux++;
	}
	return (cant);
}

char	**ft_split_custom(char *str, char C)
{
	char	**result;
	int		cant;
	int		aux;
	int		aux1;
	int		letter;

	cant = cont_words(str, C);
	aux = 0;
	letter = 0;
	result = malloc((1 + cant) * sizeof(char *));
	while (cant != aux)
	{
		letter = cont_letter(str, C);
		result[aux] = malloc(letter * sizeof(char) + 1);
		aux1 = 0;
		while (letter != aux1)
			result[aux][aux1++] = *(str++);
		result[aux][aux1] = '\0';
		aux++;
	}
	result[aux] = NULL;
	return (result);
}
