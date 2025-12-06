/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traductor_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/comands.h"

void    ft_env_tokens(void)
{
    ft_env();
    error_handle(0, 0);
}

int is_only_numero(char *str)
{
    while (str && *str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

void    ft_exit_tokens(char **tokens, int has_pipe)
{
    int len;

    len = len_all(tokens);
    if (len == 1)
        ft_exit(0);
    if (!is_only_numero(tokens[1]))
        error_handle(1, "exit: numeric argument required");
    if (len > 2)
        error_handle(1, "exit: too many arguments");
    ft_exit(ft_atoi(tokens[1]));
}