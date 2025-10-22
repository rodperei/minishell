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
#define META 4

void	compute_quotes_mask(char input, char *flg)
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
			compute_quotes_mask(*input, &flg);
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

void	is_meta(char c, char *flg)
{
	if(ft_strchr(" \t\n|<>", c))
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
	while (state == (*flg & META) && **end)
	{
		compute_quotes_mask(**end, flg);
		if ((*flg & ~META) == 0)
			is_meta(**end, flg);
		(*end)++;
	}
}

char	*save_word(char **bgn, char *end)
{
	char	*token;
	size_t	size;
	size_t	i;

	size = 0;
	while (bgn[size] != end)
		if (*bgn[size] != '"' && *bgn[size] != '\'')
			size++;
	token = malloc((size + 1) * sizeof(char));
	if (!token)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (**bgn != '"' && **bgn != '\'')
			token[i] = **bgn;
		*bgn++;
	}
	token[i] = '\0';
	return (token);
}

void	parse_redirect(char **bgn, char *operator, char *i, char c)
{
	operator[(*i)++] = c;
	if (**bgn == c)
	{
		(*bgn)++;
		operator[(*i)++] = c;
	}
}

char	*save_operator(char **bgn, char *end)
{
	char	*token;
	char	operator[3];
	char	i;

	i = 0;
	while(*bgn != end)
	{
		if (*(*bgn)++ == '|')
		{
			operator[i++] = '|';
			break ;
		}
		if (*(*bgn)++ == '<')
		{
			parse_redirect(bgn, operator, &i, '<');
			break ;
		}
		if (*(*bgn)++ == '>')
		{
			parse_redirect(bgn, operator, &i, '>');
			break ;
		}
	}
	operator[i] = '\0';
	return (ft)
}

char	**tokenize(char *end)
{
	char	**tokens;
	char	*bgn;
	char	flg;

	if (parse_quotes(end))
	{
		printf("Input error: unclosed quotes\n");
		return NULL;
	}
	end = clear_input(end);
	bgn = end;
	while (end && *end)
	{
		read_token(&end, &flg);
		is_meta(*bgn, &flg);
		if (flg < 0)
			*tokens = save_word(&bgn, end);
		else
			while (bgn != end)
				*tokens = save_operator(&bgn, end);
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
