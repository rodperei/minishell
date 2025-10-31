/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../include/parse.h"

char	**parse(char **tokens)
{
	int		aux;
	char	**parse;

	aux = -1;
	parse = NULL;
	printf("-->> %s", tokens[0]);
	if (!tokens)
		return (parse);
	while (tokens && len_all(tokens) != ++aux)
	{
		if (equal(tokens[aux], ">"))
			parse = append_matriz(parse, "\n");
		parse = append_matriz(parse, tokens[aux]);
	}
	parse = append_matriz(parse, "\n");
	return (parse);
}
