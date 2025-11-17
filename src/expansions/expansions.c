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

char	**remove_quotes(char **tokens)
{
	char	*tmp;
	size_t	i;

	i = -1;
	while (tokens[++i])
	{
		if (*tokens[i] == '\'' || *tokens[i] == '"')
		{
			tmp = ft_strtrim(tokens[i], "'\"");
			if (!tmp)
				compute_error(tokens);
			free(tokens[i]);
			tokens[i] = tmp;
		}
	}
	print_matriz_vec(tokens, "EXPAND");
	return (tokens);
}

char	**expand(char **input)
{
	size_t	i;
	char	*tmp;

	i = -1;
	while (input[++i])
	{
		if (!ft_strncmp(input[i], "<<", ft_strlen(input[i])))
		{
			i++;
			continue ;
		}
		while (*input[i] != '\'' && ft_strchr(input[i], '$'))
		{
			tmp = expand_var(input[i]);
			if (!tmp)
				compute_error(input);
			input[i] = tmp;
		}
	}
	return (remove_quotes(input));
}
