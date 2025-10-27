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

#include <stddef.h>
#include <stdlib.h>
#include "../../include/utils.h"
#include "tokenizer.h"

char	parse_quotes(char *input)
{
	char	flg;

	flg = 0;
	while (input && *input)
	{
		compute_quotes_mask(*input, &flg);
		input++;
	}
	return (flg);
}

char	**compute_saves(char **tokens, char flg, char **bgn, char *end)
{
	if ((flg & META) == 0)
		tokens = resize_tokens(tokens, save_word(bgn, end));
	else
		while (*bgn != end)
			tokens = resize_tokens(tokens, save_operator(bgn, end));
	return (tokens);
}

char	**tokenize(char *end)
{
	char	**tokens;
	char	*bgn;
	char	*tmp;
	char	flg;

	if (parse_quotes(end))
	{
		free(end);
		error_handle(0, "Input error: unclosed quotes\n");
	}
	end = clear_input(end);
	tmp = end;
	bgn = end;
	tokens = 0;
	while (end && *end)
	{
		read_token(&end, &flg);
		is_meta(*bgn, &flg);
		tokens = compute_saves(tokens, flg, &bgn, end);
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
