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

int     ft_echo_tokens(char **tokens)
{
    int     len;
    int     flag;
    int     aux;
    char    *text;

    len = len_all(tokens);
    text = NULL;
    flag = 0;
    aux = 0;
    if (len == 1)
    {
        ft_echo("", 1);
        error_handle(0, 0);
    }
    else if (len == 2 && equal("-n", tokens[1]))
        flag = 0;
    while ((++aux) != len)
        text = append(text, ft_strlen(tokens[aux]), tokens[aux]);
    ft_echo(text, flag);
    error_handle(0, 0);
}

int     ft_cd_tokens(char **tokens)
{
    int     len;
    char    *path;

    len = len_all(tokens);
    path = NULL;
    if (len > 2)
        error_handle(1, "too many arguments");
    if (len == 1)
    {
        path = ft_getenv("HOME");
        ft_cd(path);
        free(path);
    }
    else
        ft_cd(tokens[1]);
    error_handle(0, 0);
}
