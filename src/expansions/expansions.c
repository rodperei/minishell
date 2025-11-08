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

#include "../tokenizer/tokenizer.h"
#include "../../include/utils.h"
#include "./expansions.h"

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
