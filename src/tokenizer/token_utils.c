/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:09:23 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/24 18:18:28 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "tokenizer.h"

void	compute_flg_mask(char input, char *flg)
{
	if (!(*flg & SQUOTE) && !(*flg & DQUOTE) && input == '"')
		*flg |= DQUOTE;
	else if (!(*flg & DQUOTE) && !(*flg & SQUOTE) && input == '\'')
		*flg |= SQUOTE;
	else if ((*flg & SQUOTE) && input == '\'')
		*flg &= ~SQUOTE;
	else if ((*flg & DQUOTE) && input == '"')
		*flg &= ~DQUOTE;
}

void	is_meta(char c, char *flg)
{
	if (ft_strchr(" \t\n|<>", c) && (*flg & 3) == 0)
		*flg |= META;
	else
		*flg &= ~META;
}

void	read_token(char **end, char *flg)
{
	char	state;

	*flg = 0;
	is_meta(**end, flg);
	state = *flg;
	while (state == (*flg & META) && *(++(*end)))
	{
		compute_flg_mask(**end, flg);
		is_meta(**end, flg);
	}
}

char	**resize_tokens(char **list, char *new_token)
{
	size_t	size;
	size_t	i;
	char	**tmp;

	if (!new_token)
		return (NULL);
	size = 0;
	while (list && list[size])
		size++;
	tmp = malloc((size + 2) * sizeof(char *));
	if (!tmp)
	{
		free_all(list);
		free(new_token);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		tmp[i] = list[i];
	free(list);
	tmp[i++] = new_token;
	tmp[i] = 0;
	return (tmp);
}
