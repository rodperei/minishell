/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

char	*ft_resuelve_path(char *path)
{
	char	*tem;
	char	*path_complete;

	if (!path)
		return (path);
	if (path[0] == '/')
		return (ft_strdup(path));
	tem = path;
	path_complete = ft_getenv("PWD");
	if (!path_complete)
		error_handle_f(0, "Error no exist PWD\n");
	else if (ft_strlen(path) > 2 && path[0] == '.' && path[1] == '/')
	{
		path += 2;
		tem = ft_strdup(path);
	}
	path_complete = append(path_complete, 1, "/");
	path_complete = append(path_complete, ft_strlen(tem), tem);
	return (path_complete);
}
