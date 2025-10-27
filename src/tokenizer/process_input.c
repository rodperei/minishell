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
		while (ft_strchr(" \t", **input))
			(*input)++;
	}
}

char	*flush_buff(char *buff, char *dst)
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

char	*merge_wspaces(char *input)
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

	if (!input)
		return (NULL);
	tmp = input;
	input = ft_strtrim(tmp, " \n\t");
	free(tmp);
	tmp = input;
	input = merge_wspaces(tmp);
	free(tmp);
	return (input);
}
