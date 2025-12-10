/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:16:48 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/30 17:20:26 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../include/utils.h"

char	**remove_redir_tokens(char **oldt, int *i)
{
	int		j;
	size_t	k;
	char	**tokens;

	free(oldt[*i]);
	free(oldt[*i + 1]);
	tokens = malloc((len_all(oldt) - 1) * sizeof(char *));
	if (!tokens)
		error_handle(0, 0);
	j = -1;
	k = 0;
	while (oldt[++j])
	{
		if (j == *i)
			j++;
		else
			tokens[k++] = oldt[j];
	}
	tokens[k] = oldt[j];
	free(oldt);
	(*i)--;
	return (tokens);
}
