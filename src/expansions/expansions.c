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
#include <stddef.h>
#include "./expansions.h"

char	*expand_var(char *token, size_t i)
{
	char	*tmp;
	char	*result;

	result = save_prefix(token, i);
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

char	*compute_dolars(char *token)
{
	size_t	i;

	i = 0;
	while (token && token[i])
	{
		if (*token != '\'' && token[i] == '$')
			token = expand_var(token, i);
		if (token[i])
			i++;
	}
	return (token);
}

char	*expand_heredoc(char *delimiter, int *j)
{
	char	*buff;
	char	*tmp;
	char	name[15];
	char	*file_no;

	tmp = ft_strtrim(delimiter, "\"'");
	free(delimiter);
	buff = read_input(tmp);
	free(tmp);
	buff = compute_dolars(buff);
	save_buffer(buff, j);
	ft_memmove(name, "tmp", 4);
	file_no = ft_itoa((*j)++);
	ft_strlcat(name, file_no, 15);
	free(file_no);
	return (ft_strdup(name));
}

char	**expand(char **input)
{
	size_t	i;
	int		j;

	if (!input)
		exit(0);
	i = -1;
	j = 0;
	while (input[++i])
	{
		if (!ft_strncmp(input[i], "<<", calc_longer_str("<<", input[i])))
		{
			i++;
			input[i] = expand_heredoc(input[i], &j);
			continue ;
		}
		input[i] = compute_dolars(input[i]);
	}
	return (remove_quotes(input));
}
