/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:40:09 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/08 16:42:55 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

# include <stddef.h>

// expansion_utils.c
char	*save_prefix(char *token, size_t k);
char	*swap_expansion(char *prefix, char *token, size_t *i);

// hdoc_utils.c
void	save_buffer(char *buff, int	*j);
char	*read_input(char *delimiter);

// quotes_utils.c
char	**remove_quotes(char **tokens);

#endif
