/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:06:05 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/05 18:10:29 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell_functions.h"
#include "../include/utils.h"

int	main(int ac, char **av)
{
	char	**tokens;

	(void)ac;
	tokens = tokenize(ft_strdup(av[1]));
	tokens = parse(tokens);
	free_all(tokens);
}
