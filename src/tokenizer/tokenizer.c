/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:39:50 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/13 18:52:26 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm-generic/errno-base.h>
#include <stddef.h>
#include <stdlib.h>
#include "../../include/utils.h"
#include "tokenizer.h"

void	parse_quotes(char *input)
{
	char	flg;
	size_t	i;

	if (!input)
		error_handle(EIO, 0);
	flg = 0;
	i = -1;
	while (input && input[++i])
		compute_flg_mask(input[i], &flg);
	if (flg)
	{
		free(input);
		error_handle(EIO, 0);
	}
}

char	**compute_saves(char **tokens, char flg, char **bgn, char *end)
{
	char	oprt[3];
	char	*tmp;

	if ((flg & FT_META) == 0)
		tokens = resize_tokens(tokens, save_word(bgn, end, tokens));
	else
	{
		while (*bgn != end)
		{
			if (save_operator(bgn, end, oprt))
			{
				tmp = ft_strdup(oprt);
				if (!tmp)
					free_all(tokens);
				tokens = resize_tokens(tokens, tmp);
			}
		}
	}
	return (tokens);
}

char	**tokenize(char *end)
{
	char	**tokens;
	char	*bgn;
	char	*tmp;
	char	flg;

	parse_quotes(end);
	end = clear_input(end);
	tmp = end;
	bgn = end;
	tokens = 0;
	while (end && *end)
	{
		read_token(&end, &flg);
		compute_flg_mask(*end, &flg);
		is_meta(*bgn, &flg);
		tokens = compute_saves(tokens, flg, &bgn, end);
		if (!tokens)
		{
			free(tmp);
			error_handle(0, 0);
		}
	}
	free(tmp);
	return (tokens);
}
