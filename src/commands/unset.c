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

#include "../../include/utils.h"
#include "../../include/comands.h"

int	ft_unset(char *name)
{
	char	**envs;
	char	*value;
	int		aux;

	if (!name)
		error_handle_f(0, 0);
	if (!include(name, "="))
		value = ft_strjoin(name, "=");
	else
		value = ft_strdup(name);
	envs = ft_getallenv();
	aux = 0;
	while (envs && envs[aux])
	{
		if (equaln(envs[aux], value, ft_strlen(value)))
			break ;
		aux++;
	}
	if (envs && equaln(envs[aux], value, ft_strlen(value)))
		envs = delete_vec_matriz(envs, aux);
	load_env(envs);
	free_all(envs);
	free(value);
	return (0);
}
