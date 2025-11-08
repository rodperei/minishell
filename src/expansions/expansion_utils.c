/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:36:33 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/08 16:43:17 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_strdup("");
	result = ft_strjoin(prefix, tmp);
	free(tmp);
	free(prefix);
	return (result);
}
