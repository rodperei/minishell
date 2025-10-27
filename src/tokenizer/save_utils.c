/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:38:34 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/27 14:47:55 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../include/utils.h"
#include "./tokenizer.h"

char	*save_word(char **bgn, char *end)
{
	char	*token;
	size_t	i;
	char	*tmp;

	tmp = *bgn;
	i = 0;
	while (tmp != end)
	{
		if (!ft_strchr(" \t\n|<>\"'", *tmp))
			i++;
		tmp++;
	}
	token = malloc((i + 1) * sizeof(char));
	if (!token)
		return (NULL);
	i = 0;
	while (*bgn != end)
	{
		if (!ft_strchr(" \t\n|<>\"'", **bgn))
			token[i++] = **bgn;
		(*bgn)++;
	}
	token[i] = '\0';
	return (token);
}

void	compute_operators(char **bgn, char *oprt, int *i)
{
	if (**bgn == '|')
		oprt[(*i)++] = '|';
	else if (**bgn == '\n')
		oprt[(*i)++] = '\n';
	else if (**bgn == '<')
		parse_redirect(bgn, oprt, i, '<');
	else if (**bgn == '>')
		parse_redirect(bgn, oprt, i, '>');
	(*bgn)++;
}

char	*save_operator(char **bgn, char *end)
{
	char	operator[3];
	int		i;

	i = 0;
	while (*bgn != end)
	{
		if (ft_strchr("|<>\n", **bgn))
		{
			compute_operators(bgn, operator, &i);
			break;
		}
		(*bgn)++;
	}
	operator[i] = '\0';
	if (i == 0)
		return (NULL);
	else
		return (ft_strdup(operator));
}
