/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:39:11 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/25 15:49:20 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "../../include/utils.h"
#include <stddef.h>

void	shrink_wspace(char *input, char *buff, int *i, size_t *j)
{
	if (*input == '\n' && *i < 99)
	{
		buff[(*i++)] = input[(*j)++];
		while (ft_strchr(" \t\n", input[*j]))
			(*j)++;
	}
	else if (*i < 99)
	{
		buff[(*i++)] = ' ';
		(*j)++;
		while (ft_strchr(" \t", *input))
			(*j)++;
	}
}

char	*flush_buff(char *buff, char *dst, char *input)
{
	char	*tmp;

	tmp = ft_strjoin(dst, buff);
	if (!tmp)
	{
		free(input);
		error_handle(0, 0);
	}
	if (dst)
		free(dst);
	while (*buff)
		*buff++ = '\0';
	return (tmp);
}

char	*merge_wspaces(char *input)
{
	char	flg;
	char	buff[100];
	char	*clean_input;
	int		i;
	size_t	j;

	i = -1;
	j = 0;
	flg = 0;
	clean_input = 0;
	while (input && input[j])
	{
		while (++i < 99 && input[j])
		{
			compute_quotes_mask(input[j], &flg);
			if (!flg && ft_strchr(" \n\t", input[j]))
				shrink_wspace(input, buff, &i, &j);
			else
				buff[i] = input[j++];
		}
		buff[i] = '\0';
		clean_input = flush_buff(buff, clean_input, input);
	}
	return (clean_input);
}

char	*clear_input(char *input)
{
	char	*tmp;

	tmp = input;
	input = ft_strtrim(tmp, " \n\t");
	if (!input)
	{
		free(tmp);
		error_handle(0, 0);
	}
	free(tmp);
	tmp = input;
	input = merge_wspaces(tmp);
	free(tmp);
	return (input);
}
