/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:25:07 by frnicola          #+#    #+#             */
/*   Updated: 2025/06/21 19:25:09 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_sing(unsigned long hex, int itera)
{
	char	*hex_str;
	int		max;

	max = 0;
	hex_str = "0123456789abcdef";
	if (!hex)
	{
		put_str("(nil)");
		return (5);
	}
	if (hex >= 16)
	{
		max = put_hex_sing(hex / 16, ++itera);
		if (max > itera)
			itera = max;
	}
	if (hex < 16)
	{
		put_str("0x");
		itera += 3;
	}
	put_char(hex_str[hex % 16]);
	return (itera);
}

int	put_hex(unsigned int hex, int mayus, int itera)
{
	char	*hex_str;
	int		max;

	hex_str = "0123456789abcdef";
	max = 0;
	if (mayus)
		hex_str = "0123456789ABCDEF";
	if (hex >= 16)
	{
		max = put_hex(hex / 16, mayus, ++itera);
		if (max > itera)
			itera = max;
	}
	if (hex < 16)
		itera++;
	put_char(hex_str[hex % 16]);
	return (itera);
}
