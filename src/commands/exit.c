/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

int	parce_num(int num)
{
	return (num % 256);
}

void	last_exit(void)
{
	char	*last_status;
	int		status_num;

	last_status = ft_getenv("?");
	status_num = ft_atoi(last_status);
	free(last_status);
	status_num = parce_num(status_num);
	unlink(name_env());
	free(name_env());
	exit(status_num);
}

void	ft_exit(int status)
{
	char	*tem;

	tem = ft_itoa(status);
	ft_export("??", tem);
	ft_export("?", tem);
	free(tem);
	status = parce_num(status);
	exit(status);
}
