/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:37:54 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/02 17:55:18 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux/limits.h>
#include <stddef.h>
#include "../tokenizer/tokenizer.h"
#include "../../include/utils.h"
#include "../../include/comands.h"

#define BUFFER_SIZE 100

char	*flush_name(char *dst, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(dst, buff);
	if (!tmp)
		return (NULL);
	if (dst)
		free(dst);
	while (*buff)
		*buff++ = '\0';
	return (tmp);
}

char	*fetch_var_name(char *token, size_t *i)
{
	size_t	j;
	char	buff[BUFFER_SIZE];
	char	*expanded_token;
	char	*chr;

	expanded_token = 0;
	chr = ft_strchr(" \t\n", token[*i]);
	while (token[*i] && !chr)
	{
		j = 0;
		while (j < BUFFER_SIZE - 1 && token[*i] && !chr)
		{
			buff[j++] = token[(*i)++];
			chr = ft_strchr(" \t\n", token[*i]);
		}
		buff[j] = '\0';
		expanded_token = flush_name(expanded_token, buff);
		if (!expanded_token)
			return (NULL);
	}
	return (expanded_token);
}

char	*save_prefix(char *token, size_t *i)
{
	char	buff[BUFFER_SIZE];
	size_t	j;
	char	*result;

	result = 0;
	while (token[*i] && token[*i] != '$')
	{
		j = 0;
		while (j < BUFFER_SIZE - 1 && token[*i] && token[*i] != '$')
			buff[j++] = token[(*i)++];
		buff[j] = '\0';
		result = flush_name(result, buff);
		if (!result)
			return (NULL);
	}

	return (result);
}

char	*swap_expansion(char *prefix, char *token, size_t *i)
{
	char	*result;
	char	*tmp;

	result = fetch_var_name(token, i);
	if (!result)
		return (NULL);
	tmp = ft_getenv(result);
	free(result);
	if (!tmp)
		tmp = "";
	result = ft_strjoin(prefix, tmp);
	free(tmp);
	free(prefix);
	return (result);
}

char	*expand_var(char *token)
{
	char	*tmp;
	char	*result;
	size_t	i;

	i = 0;
	result = save_prefix(token, &i);
	if (!result)
		return (NULL);
	i++;
	tmp = swap_expansion(result, token, &i);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, &token[i]);
	free(tmp);
	if (!result)
		return (NULL);
	free(token);
	return (result);
}

void	compute_error(char **tokens)
{
	free_all(tokens);
	error_handle(0, 0);
}

char	*remove_quotes(char	*token)
{
	char	*tmp;

	if (*token == '\'' || *token == '"')
	{
		tmp = ft_strtrim(token, "'\"");
		if (!tmp)
			return (NULL);
		free(token);
		return (tmp);
	}
	return (token);
}

char	**expand(char **input)
{
	size_t	i;
	char	*tmp;
	char	flg;

	i = -1;
	while (input[++i])
	{
		compute_quotes_mask(*input[i], &flg);
		while (ft_strchr(input[i], '$') && !(flg & SQUOTE))
		{
			tmp = expand_var(input[i]);
			if (!tmp)
				compute_error(input);
			input[i] = tmp;
		}
	}
	i = -1;
	while (input[++i])
	{
		tmp = remove_quotes(input[i]);
		if (!tmp)
			compute_error(input);
		input[i] = tmp;
	}
	return (input);
}
