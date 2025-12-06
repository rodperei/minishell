/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:48:02 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/24 15:53:26 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	error_handle(int err, char	*str)
{
	if (err != 0)
	{
		if (!str)
			printf("%s\n", strerror(err));
		else
			printf("%s\n", str);
	}
	exit(err);
}
