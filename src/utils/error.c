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

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "../../include/utils.h"

void	error_handle(int err, char *str)
{
	char	*str_err;

	str_err = strerror(errno);
	if (err != 0)
	{
		if (!str)
			write(STDERR_FILENO, str_err, ft_strlen(str_err));
		else
			write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, "\n", 1);
		exit(err);
	}
	if (err == 0 && !str)
	{
		write(STDERR_FILENO, str_err, ft_strlen(str_err));
		write(STDERR_FILENO, "\n", 1);
		exit(errno);
	}
}

void	error_handle_f(int err, char *str)
{
	char	*str_err;

	str_err = strerror(errno);
	if (err != 0)
	{
		if (!str)
			write(STDERR_FILENO, str_err, ft_strlen(str_err));
		else
			write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(err);
}
