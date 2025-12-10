/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:43:29 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/10 14:46:49 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char	check_snip(char c, char *flg)
{
	char	state;

	state = *flg;
	compute_flg_mask(c, flg);
	if ((state & 3) != (*flg & 3))
		return (1);
	return (0);
}

char	*snip_quote(char *token, char c)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*new_token;

	size = 0;
	i = -1;
	while (token[++i])
		size++;
	i = 0;
	while (token[i] && token[i] != c)
		i++;
	token[i] = '\0';
	new_token = malloc(size * sizeof(char));
	i = -1;
	j = 0;
	while (j < size - 1)
		if (token[++i])
			new_token[j++] = token[i];
	new_token[j] = '\0';
	free(token);
	return (new_token);
}

char	**remove_quotes(char **tokens)
{
	size_t	i;
	size_t	j;
	char	flg;
	char	snip;

	i = -1;
	while (tokens[++i])
	{
		flg = 0;
		j = 0;
		while (tokens[i][j])
		{
			snip = check_snip(tokens[i][j], &flg);
			if (snip && tokens[i][j] == '\'')
				tokens[i] = snip_quote(tokens[i], '\'');
			else if (snip)
				tokens[i] = snip_quote(tokens[i], '"');
			if (tokens[i][j] && !snip)
				j++;
		}
	}
	return (tokens);
}
