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

int	valid_name(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x])
	{
		if ((str[x] > 'a' && str[x] < 'z') || (str[x] > 'A' && str[x] < 'Z'))
			x++;
		else
			return (0);
	}
	return (1);
}

int	ft_export(char *name, char *value)
{
	char	**envs;
	char	*result;

	if (!value || !valid_name(name))
		error_handle(1, " not a valid identifier");
	if (!include(name, "="))
		result = ft_strjoin(name, "=");
	else
		result = ft_strdup(name);
	ft_unset(name);
	result = append(result, len(value), value);
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