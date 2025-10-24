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
#include "../src/utils/utils.h"
#include <stdio.h>

int	main(void)
{
	char	*str = "\n\n\tTest the \nTokens\n\n\tof    the token\nizer<<<<<>|||\n\n\n";
	char	**tokens;
	int		i = 0;

	tokens = tokenize(str);
	printf("str: |%s|\n\n", str);
	while (tokens[i])
		printf("token %d: %s\n", i, tokens[i]);
	free_all(tokens);
}
