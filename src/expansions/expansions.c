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

char	check_snip(char c, char *flg)
{
	char	state;

	state = *flg;
	compute_flg_mask(c, flg);
	if ((state & 3) != (*flg & 3))
		return (1);
	return (0);
}

char	*snip_quote(char *token, char c)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*new_token;

	size = 0;
	i = -1;
	while (token[++i])
		size++;
	i = 0;
	while (token[i] && token[i] != c)
		i++;
	token[i] = '\0';
	new_token = malloc(size * sizeof(char));
	i = -1;
	j = 0;
	while (j < size - 1)
		if (token[++i])
			new_token[j++] = token[i];
	new_token[j] = '\0';
	free(token);
	return (new_token);
}

char	**remove_quotes(char **tokens)
{
	size_t	i;
	size_t	j;
	char	flg;
	char	snip;

	i = -1;
	while (tokens[++i])
	{
		flg = 0;
		j = 0;
		while (tokens[i][j])
		{
			snip = check_snip(tokens[i][j], &flg);
			if (snip && tokens[i][j] == '\'')
				tokens[i] = snip_quote(tokens[i], '\'');
			else if (snip)
				tokens[i] = snip_quote(tokens[i], '"');
			if (tokens[i][j] && !snip)
				j++;
		}
	}
	return (tokens);
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
	while (ft_strchr(buff, '$'))
		buff = expand_var(buff);
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
	size_t	k;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	while (input[++i])
	{
		if (!ft_strncmp(input[i], "<<", ft_strlen(input[i])))
		{
			i++;
			input[i] = expand_heredoc(input[i], &j);
			continue ;
		}
		k = -1;
		while (input[i][++k])
		{
			if (*input[i] != '\'' && input[i][k] == '$')
			{
				tmp = expand_var(input[i]);
				if (!tmp)
					compute_error(input);
				input[i] = tmp;
			}
		}
	}
	return (remove_quotes(input));
}
