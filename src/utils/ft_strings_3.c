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

#include <stdlib.h>

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

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dsize)
		i++;
	if (i == dsize)
		return (count_size(i, j, src));
	while (src[j] && (i + 1) < dsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (count_size(i, j, src));
}
