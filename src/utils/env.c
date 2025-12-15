/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:57:18 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/10 13:59:27 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"
#include <dirent.h>

char	*name_env(void)
{
	static int	cont = -1;
	static char	*result;
	DIR			*path;

	if (cont == -1)
	{
		path = opendir("/tem");
		while (readdir(path))
			cont++;
		closedir(path);
		result = ft_strjoin(FILE_ENV, ft_itoa(cont));
	}
	return (result);
}
