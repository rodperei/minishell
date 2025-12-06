/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

int	ft_export(char *name, char *value)
{
	char	**envs;
	char	*result;

	if (!value || !name)
		error_handle(1, "not a valid identifier");
	result = ft_strjoin(name, "=");
	result = append(result, len(value), value);
	ft_unset(name);
	envs = ft_getallenv();
	envs = append_matriz(envs, result);
	load_env(envs);
	free_all(envs);
	free(result);
	return (0);
}

void	ft_export_void(void)
{
	char	**env;
	int		aux;

	env = ft_getallenv();
	aux = 0;
	while (env[aux])
	{
		printf("declare -x %s\n", env[aux]);
		aux++;
	}
	free_all(env);
}