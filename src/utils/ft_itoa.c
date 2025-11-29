/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:58:15 by rodperei          #+#    #+#             */
/*   Updated: 2025/04/14 15:09:42 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../include/utils.h"

static void	fill_temp_arr(char *t, int *nb, int i)
{
	int		j;
	char	rvers[11];

	j = 0;
	while (*nb >= 10)
	{
		rvers[j++] = (*nb % 10) + '0';
		*nb = *nb / 10;
	}
	rvers[j++] = (*nb % 10) + '0';
	while (j > 0)
		t[i++] = rvers[--j];
	t[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	char	temp[12];

	if (n == INT_MIN)
		ft_strlcpy(temp, "-2147483648", sizeof(temp));
	else
	{
		i = 0;
		if (n < 0)
		{
			temp[i] = '-';
			i++;
			n = -n;
		}
		fill_temp_arr(temp, &n, i);
	}
	p = ft_strdup(temp);
	if (!p)
		return (NULL);
	return (p);
}
/*
#include <stdio.h>
int main(void)
{
	int		nb = INT_MIN;
	char	*p = ft_itoa(nb);

	printf("%s\n", p);
}*/
