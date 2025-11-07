/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:47:09 by rodperei          #+#    #+#             */
/*   Updated: 2025/10/22 17:48:52 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/helper_functions.h"
#include "../include/utils.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	**tokens;
	int		i;

	str = "|     |        |   \"\"  ''   |     \"|     |\"    '|    |'";
	str = ft_strdup(str);
	printf("str: |%s|\n\n", str);
	tokens = tokenize(str);
	i = -1;
	while (tokens[++i])
		printf("token %d: %s\n", i, tokens[i]);
	free_all(tokens);
}
