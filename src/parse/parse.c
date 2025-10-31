/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/parse.h"

void	case_split(char ***parse, char **tokens, int aux)
{
	if (equal(tokens[aux], ">"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], "<"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], "<<"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], ">>"))
		(*parse) = append_matriz((*parse), "\n");
	else if (equal(tokens[aux], "|"))
		(*parse) = append_matriz((*parse), "\n");
}

void	shear_error(char **tokens, int aux)
{
	int		max;
	char	*errors[10];
	int		err;
	int		tem;

	errors[0] = ">";
	errors[1] = ">>";
	errors[2] = "<<";
	errors[3] = "<";
	errors[4] = "|";
	errors[5] = NULL;
	max = len_all(tokens);
	err = 0;
	while (errors[err] && tokens[aux])
	{
		tem = -1;
		while (equal(tokens[aux], errors[err]) && errors[++tem])
		{
			if (equal(tokens[aux + 1], errors[tem]))
				error_handle(0, "syntax error near unexpected token");
		}
		if (equal(tokens[aux], errors[err]) && !tokens[aux + 1])
			error_handle(0, "syntax error near unexpected token");
		err++;
	}
}

char	**parse(char **tokens)
{
	int		aux;
	char	**parse;

	aux = -1;
	parse = NULL;
	if (!tokens)
		return (parse);
	print_matriz_vec(tokens, "tokens");
	while (tokens && len_all(tokens) != ++aux)
	{
		shear_error(tokens, aux);
		case_split(&parse, tokens, aux);
		parse = append_matriz(parse, tokens[aux]);
	}
	parse = append_matriz(parse, "\n");
	print_matriz_vec(parse, "parse");
	return (parse);
}
