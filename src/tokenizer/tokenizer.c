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
#include "../utils/utils.h"

#define SQUOTE 1
#define DQUOTE 2

void	compute_quotes_mask(char *input, char *flg)
{
	if (!(*flg & SQUOTE) && !(*flg & DQUOTE) && *input == '"')
		*flg |= DQUOTE;
	else if (!(*flg & DQUOTE) && !(*flg & SQUOTE) && *input == '\'')
		*flg |= SQUOTE;
	else if ((*flg & SQUOTE) && *input == '\'')
		*flg &= ~SQUOTE;
	else if ((*flg & DQUOTE) && *input == '"')
		*flg &= ~DQUOTE;
}

char	parse_quotes(char *input)
{
	char	flg;

	flg = 0;
	while (input && *input)
	{
		compute_quotes_mask(input, &flg);
		input++;
	}
	return (flg);
}

void	shrink_wspace(char **input, char *buff, int *i)
{
	if (**input == '\n' && *i < 99)
	{
		buff[(*i++)] = *(*input)++;
		while (ft_strchr(" \t\n", **input))
			(*input)++;
	}
	else if (*i < 99)
	{
		buff[(*i++)] = ' ';
		(*input)++;
		while(ft_strchr(" \t", **input))
			(*input)++;
	}
}

char	*flush_buff(char *buff, char *dst)
{
	char *tmp;

	tmp = ft_strjoin(dst, buff);
	if (!tmp)
		return (NULL);
	if (dst)
		free(dst);
	while (*buff)
		*buff++ = '\0';
	return (tmp);
}

char *merge_wspaces(char *input)
{
	char	flg;
	char	buff[100];
	char	*clean_input;
	int		i;

	i = -1;
	flg = 0;
	clean_input = 0;
	while (input && *input)
	{
		while (++i < 99 && *input)
		{
			compute_quotes_mask(input, &flg);
			if (!flg && ft_strchr(" \n\t", *input))
				shrink_wspace(&input, buff, &i);
			else
				buff[i] = *input++;
		}
		buff[i] = '\0';
		clean_input = flush_buff(buff, clean_input);
		if (!clean_input)
			return (NULL);
	}
	return (clean_input);
}

char	*clear_input(char *input)
{
	char	*tmp;

	if (input)
		return (NULL);
	tmp = input;
	input = ft_strtrim(tmp, " \n\t");
	free(tmp);
	tmp = input;
	input = merge_wspaces(tmp);
	free(tmp);
	return (input);
}

char	is_meta(char c)
{
	if(ft_strchr(" \t\n|<>", c))
		return (1);
	return (0);
}

void	read_token(char **input, char **end, char *flg)
{
	char	state;

	state = *flg;
	while (state == *flg && **input)
	{
		(*end)++;
		(*input)++;
		*flg = is_meta(**input);
	}
}

char	*save_word(char *bgn, char *end)
{
	char	*token;
	size_t	size;
	size_t	i;

	size = 0;
	while (&bgn[size] != end)
		size++;
	token = malloc((size + 1) * sizeof(char));
	if (!token)
		return (NULL);
	i = -1;
	while (++i < size)
		token[i] = bgn[i];
	token[i] = '\0';
	return (token);
}

char	*save_operator(char *bgn, char *end)
{
	char	*token;
	size_t	size;

	size = 0;
	while (&bgn[size] != end)
		size++;

}

char	**tokenize(char *input)
{
	char	**tokens;
	char	*bgn;
	char	*end;
	char	flg;

	if (parse_quotes(input))
	{
		printf("Input error: unclosed quotes\n");
		return NULL;
	}
	input = clear_input(input);
	flg = is_meta(*input);
	bgn = input;
	end = input;
	while (input && *input)
	{
		read_token(&input, &end, &flg);
		if (!is_meta(*bgn))
			*tokens = save_word(bgn, end);
		else
			*tokens = save_operator(bgn, end);
		bgn = end;
		tokens++;
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
