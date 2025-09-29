/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/utils.h"
#include "../../../include/comands.h"

void	up(char *pwd)
{
	int		aux;
	int		last;

	aux = 0;
	last = 0;
	while (pwd && pwd[aux])
	{
		if (pwd[aux] == '/')
			last = aux;
		aux++;
	}
	pwd[last + 1] = '\0';
}

int	ft_cd(char *path)
{
	char	*pwd;

	pwd = ft_getenv("PWD");
	if (!pwd)
		error("Error: not exist PWD en env");
	if (!path)
		error("Error: *path is NULL");
	if (equal(path, ".."))
		up(pwd);
	ft_export("PWD", pwd);
	free(pwd);
	return (1);
}
