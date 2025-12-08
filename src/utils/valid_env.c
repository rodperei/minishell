/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

void	valid_env()
{
	char	*tmp;

	tmp = ft_getenv("PWD");
	if (!tmp)
	{
		tmp = malloc(PATH_MAX * sizeof(char));
		getcwd(tmp, PATH_MAX);
		ft_export("PWD", tmp);
	}
	free(tmp);
	tmp = ft_getenv("PATH");
	if (!tmp)
	{
		tmp = ft_strdup("/usr/local/sbin:/usr/local/bin:/usr/sbin:\
/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
		ft_export("PATH", tmp);
	}
	free(tmp);
	ft_export("?", "0");
}