/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:20:30 by frnicola          #+#    #+#             */
/*   Updated: 2025/04/12 18:20:44 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	num_in_str(long nLong, char *str, int num_digit)
{
	int		module;

	if (nLong == 0)
	{
		str[0] = '0';
	}
	if (nLong < 0)
	{
		nLong *= -1;
		str[0] = '-';
	}
	num_digit--;
	while (nLong)
	{
		module = nLong % 10;
		nLong = nLong / 10;
		str[num_digit] = module + '0';
		num_digit--;
	}
}

char	*ft_itoa(int n)
{
	int		num_digit;
	char	*str;

	num_digit = count_digit(n);
	str = (char *) malloc((sizeof(char) * num_digit) + 1);
	if (!str)
		return (NULL);
	num_in_str(n, str, num_digit);
	str[num_digit] = '\0';
	return (str);
}
