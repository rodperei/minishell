/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char	*copy_vec(char *str)
{
	int		x;
	char	*result;
	int		aux;

	x = len(str);
	result = malloc((x + 1) * sizeof(char));
	if (!result)
		return (NULL);
	aux = 0;
	while (aux != x)
	{
		result[aux] = str[aux];
		aux++;
	}
	result[aux] = '\0';
	return (result);
}

char	*z_maloc(int size)
{
	char	*vec;

	vec = malloc(sizeof(char) * (size + 1));
	while (size)
	{
		vec[size] = '\0';
		size--;
	}
	vec[0] = '\0';
	return (vec);
}

char	*append(char *vec, int size_new, char *buff)
{
	char	*new;
	char	*vec_ori;
	char	*new_ori;

	if (vec == NULL)
		vec = z_maloc(size_new);
	vec_ori = vec;
	new = z_maloc(len(vec) + size_new);
	new_ori = new;
	while (vec && *vec)
	{
		*new = *vec;
		vec++;
		new++;
	}
	while (buff && *buff && size_new--)
	{
		*new = *buff;
		buff++;
		new++;
	}
	*new = '\0';
	if (vec_ori)
		free(vec_ori);
	return (new_ori);
}

int	count_caracter(char *mp, char c)
{
	int	ax;
	int	result;

	ax = 0;
	result = 0;
	while (mp && mp[ax])
	{
		if (mp[ax] == c)
			result++;
		ax++;
	}
	return (result);
}

int	include(char *str_long, char *str_small)
{
	int	aux;
	int	aux1;

	aux = 0;
	while (str_long && str_long[aux])
	{
		aux1 = 0;
		while (str_small[aux1] && str_long[aux + aux1] == str_small[aux1])
			aux1++;
		if (aux1 == len(str_small))
			return (1);
		aux++;
	}
	return (0);
}
