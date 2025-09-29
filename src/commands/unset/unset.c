/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/utils.h"
#include "../../../include/comands.h"

int	ft_unset(char *name)
{
	char	**envs;
	char	*value;
	int		aux;

	if (!name)
		error("error null variable");
	value = ft_strjoin(name, "=");
	envs = ft_getallenv();
	aux = 0;
	while (envs && envs[aux])
	{
		if (include(envs[aux], value))
			break ;
		aux++;
	}
	if (include(envs[aux], value))
		envs = delete_vec_matriz(envs, aux);
	load_env(envs);
	free_all(envs);
	free(value);
	return (0);
}
