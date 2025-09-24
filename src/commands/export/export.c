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

#include "../comands.h"

int	export(char *value)
{
	char	**envs;

	if (!value)
		error("error null variable");
	if (count_caracter(value, '=') != 1)
		error("can only be a single '='");
	envs = ft_getallenv();
	envs = append_matriz(envs, value);
	load_env(envs);
	free_all(envs);
	return (0);
}
