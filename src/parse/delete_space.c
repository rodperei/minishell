/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char    **delete_space(char **tokens)
{
    char    **result;
    int     aux1;
    int     aux2;

    result = z_maloc_matriz(len_all(tokens));
    aux1 = 0;
    aux2 = 0;
    while (aux1 != len_all(tokens))
    {
        if (len(tokens[aux1]))
        {
            result[aux2] = ft_strdup(tokens[aux1]);
            aux2++;
        }
        aux1++;
    }
    free_all(tokens);
    return (result);
}