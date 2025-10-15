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

#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

#define SQUOTE 1
#define DQUOTE 2

char	parse_quotes(char *input)
{
	char	flg;

	flg = 0;
	while (input && *input)
	{
		if (!(flg & SQUOTE) && !(flg & DQUOTE) && *input == '"')
			flg |= DQUOTE;
		else if (!(flg & DQUOTE) && !(flg & SQUOTE) && *input == '\'')
			flg |= SQUOTE;
		else if ((flg & SQUOTE) && *input == '\'')
			flg &= ~SQUOTE;
		else if ((flg & DQUOTE) && *input == '"')
			flg &= ~DQUOTE;
		input++;
	}
	return (flg);
}

char *shrink_wspace(char *input)

char	*clean_input(char *input)
{
	char	*tmp;

	tmp = input;
	input = ft_strtrim(tmp, " \n\t");
	free(tmp);
	tmp = input;
	input = shrink_wspace(tmp);
	free(tmp);
	return (input);
}

char	**tokenize(char *input)
{
	if (parse_quotes(input))
	{
		printf("Input error: unclosed quotes\n");
		return NULL;
	}
	input = clean_input(input);
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
}*/
