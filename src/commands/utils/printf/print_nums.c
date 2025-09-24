/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:25:07 by frnicola          #+#    #+#             */
/*   Updated: 2025/06/21 19:25:09 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_uni(unsigned int num, int itera)
{
	char	*num_str;
	int		max;

	num_str = "0123456789";
	if (num >= 10)
	{
		max = put_num(num / 10, ++itera);
		if (max > itera)
			itera = max;
	}
	else if (num < 10)
		itera++;
	put_char(num_str[num % 10]);
	return (itera);
}

int	put_num(int num, int itera)
{
	char	*num_str;
	int		max;

	num_str = "0123456789";
	if (num == -2147483648)
	{
		put_str("-2147483648");
		return (11);
	}
	if (num < 0)
	{
		put_char('-');
		num *= -1;
		itera++;
	}
	if (num >= 10)
	{
		max = put_num(num / 10, ++itera);
		if (max > itera)
			itera = max;
	}
	else if (num < 10)
		itera++;
	put_char(num_str[num % 10]);
	return (itera);
}
