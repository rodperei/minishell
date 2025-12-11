/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:01:58 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/11 13:10:11 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

void	verryfi_env_cwd(int status, char **env_save)
{
	char	*pwd;
	char	**env;

	env = ft_getallenv();
	if ((!env || len_all(env) < 2) && env_save)
		load_env(env_save);
	if (env)
		free_all(env);
	if (status)
		return ;
	pwd = ft_getcwd();
	if (!pwd)
		return ;
	chdir(pwd);
	free(pwd);
}

int	search_pipe(char *str)
{
	char	flg;

	flg = 0;
	while (str && *str)
	{
		compute_flg_mask(*str, &flg);
		if (!flg && ft_strchr("|", *str))
			return (1);
		str++;
	}
	return (0);
}
