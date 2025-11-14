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

	if (!input)
		error_handle(EIO, 0);
	flg = 0;
	while (input && *input)
	{
		compute_flg_mask(*input, &flg);
		input++;
	}
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

	if ((flg & META) == 0)
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

/*
#include <stdio.h>
int main(void)
{
	parse_quotes test
	char *str[9];
	str[0] = "\"\"";
	str[1] = "\'\'";
	str[2] = "\"\'\"";
	str[3] = "\'\"\'";
	str[4] = "No string test";
	str[5] = "\'\'\'";
	str[6] = "\"\"\"";
	str[7] = "";
	str[8] = 0;
	int	i = -1;

	while (++i < 9)
	{
		printf("Test %d: %d\n", i, parse_quotes(str[i]));
	}
	clear_input test
	char	*str = "  \t\t\nThis    \t is a string\n\t \n\ntest\t\t\n\n\n";
	char	*mem;

	mem = ft_strjoin(0, str);
	printf("|%s|\n", mem);
	mem = clear_input(mem);
	printf("|%s|\n", mem);
	free(mem);
	clear_input(0);
}*/
