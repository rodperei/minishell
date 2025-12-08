/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traductor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

void	ft_echo_tokens(char **tokens)
{
	int		len;
	int		flag;
	int		aux;
	char	*text;

	len = len_all(tokens);
	text = NULL;
	flag = 0;
	if (len == 1)
	{
		ft_echo("\n", 1);
		error_handle(0, 0);
	}
	else if (len >= 2 && equal("-n", tokens[1]))
		flag = 1;
	aux = flag;
	while ((++aux) != len)
	{
		text = append(text, ft_strlen(tokens[aux]), tokens[aux]);
		if (aux + 1 != len && ft_strlen(tokens[aux]))
			text = append(text, ft_strlen(" "), " ");
	}
	ft_echo(text, flag);
	error_handle(0, 0);
}

void	ft_cd_tokens(char **tokens, int has_pipe)
{
	int		len;
	char	*path;

	len = len_all(tokens);
	path = NULL;
	if (len > 2)
		error_handle(1, "cd: too many arguments");
	if (len == 1)
	{
		path = ft_getenv("HOME");
		if (!path)
			error_handle(1, "cd: HOME not set");
		if (!has_pipe)
			ft_cd(path);
		free(path);
	}
	else if (!has_pipe)
		ft_cd(tokens[1]);
	error_handle(0, 0);
}

void	ft_pwd_tokens(void)
{
	char	*pwd;

	pwd = ft_pwd();
	printf("%s\n", pwd);
	free(pwd);
	error_handle(0, 0);
}

void	ft_export_tokens(char **tokens, int has_pipe)
{
	int		len;
	int		aux;
	char	**str;

	aux = 0;
	len = len_all(tokens);
	if (len == 1)
		ft_export_void();
	while (++aux != len)
	{
		str = ft_split_custom(tokens[aux], '=');
		if (include(str[0], "?") || !valid_name_export(str[0]))
			error_handle(1, " not a valid identifier");
		if (has_pipe)
			continue ;
		if (len_all(str) == 2)
			ft_export(str[0], str[1]);
		else
			ft_export(str[0], "");
	}
	error_handle(0, 0);
}

void	ft_unset_tokens(char **tokens, int has_pipe)
{
	int	len;
	int	aux;

	aux = 0;
	len = len_all(tokens);
	if (len == 1)
		error_handle(0, 0);
	while (++aux != len)
	{
		if (has_pipe)
			continue ;
		if (!include(tokens[aux], "?"))
			ft_unset(tokens[aux]);
	}
	error_handle(0, 0);
}
