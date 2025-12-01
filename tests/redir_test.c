/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:09:37 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/30 13:10:35 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell_functions.h"
#include "../include/utils.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	**tokens;
	int		fds[REDIR_MAX];
	int		i;

	if (argc < 2)
		return (0);
	i = -1;
	while (++i < REDIR_MAX)
		fds[i] = -2;
	tokens = tokenize(ft_strdup(argv[1]));
	tokens = expand(tokens);
	tokens = redirection(tokens, fds);
	printf("%s", argv[2]);
	free_all(tokens);
	i = -1;
	while (fds[++i] != -2)
		close(fds[i]);
}
