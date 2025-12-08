/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:43:51 by frnicola          #+#    #+#             */
/*   Updated: 2025/04/10 19:44:04 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static int	is_space(char x)
{
	return ((x >= 9 && x <= 13) || (x == 32));
}

static int	is_num(char x)
{
	return (x >= '0' && x <= '9');
}

int	ft_atoi(const char *string)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	if (!string)
		return (0);
	while (is_space(*string))
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (is_num(*string))
	{
		num = (num * 10) + (*string - '0');
		string++;
	}
	return (num * sign);
}
