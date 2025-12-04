/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:31:36 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/22 17:35:19 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../include/utils.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i])
		i++;
	i++;
	p = malloc(i * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_replace(char *str, char init, char end)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == init)
			str[i] = end;
		i++;
	}
	return (str);
}

unsigned int	count_size(unsigned int i, unsigned int j, const char *src)
{
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}

size_t	calc_longer_str(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 > l2)
		return (l1);
	else
		return (l2);
}
