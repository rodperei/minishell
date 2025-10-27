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

char	*save_word(char **bgn, char *end)
{
	char	*token;
	size_t	i;
	char	*tmp;

	tmp = *bgn;
	i = 0;
	while (tmp != end)
	{
		if (!ft_strchr(" \t\n|<>\"'", *tmp))
			i++;
		tmp++;
	}
	token = malloc((i + 1) * sizeof(char));
	if (!token)
		return (NULL);
	i = 0;
	while (*bgn != end)
	{
		if (!ft_strchr(" \t\n|<>\"'", **bgn))
			token[i++] = **bgn;
		(*bgn)++;
	}
	token[i] = '\0';
	return (token);
}

void	compute_operators(char **bgn, char *oprt, int *i)
{
	if (**bgn == '|')
		oprt[(*i)++] = '|';
	else if (**bgn == '\n')
		oprt[(*i)++] = '\n';
	else if (**bgn == '<')
		parse_redirect(bgn, oprt, i, '<');
	else if (**bgn == '>')
		parse_redirect(bgn, oprt, i, '>');
}

char	*save_operator(char **bgn, char *end)
{
	char	operator[3];
	int		i;

	i = 0;
	while (*bgn != end)
	{
		if (ft_strchr("|<>\n", **bgn))
		{
			compute_operators(bgn, operator, &i);
			(*bgn)++;
			break;
		}
		(*bgn)++;
	}
	operator[i] = '\0';
	if (i == 0)
		return (NULL);
	else
		return (ft_strdup(operator));
}

char	**tokenize(char *end)
{
	char	**tokens;
	char	*bgn;
	char	flg;

	if (parse_quotes(end))
	{
		printf("Input error: unclosed quotes\n");
		return (NULL);
	}
	end = clear_input(end);
	bgn = end;
	tokens = 0;
	while (end && *end)
	{
		read_token(&end, &flg);
		is_meta(*bgn, &flg);
		if ((flg & META) == 0)
			tokens = resize_tokens(tokens, save_word(&bgn, end));
		else
			while (bgn != end)
				tokens = resize_tokens(tokens, save_operator(&bgn, end));
	}
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
