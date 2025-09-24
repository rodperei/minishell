/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:12:55 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/13 14:12:57 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./printf/ft_printf.h"

# define INI 0
# define PROS 1
# define END 2

# define WR 1
# define RE 0

// utils_vec.c
char	*copy_simple(char *str);
char	*z_maloc(int size);
char	*append(char *vec, int size_new, char *buff);

//	lens.c
int		len(char *str);
int		len_all(char **str);
int		equal(char *str, char *str1);

// ft_split.c
void	free_all(char **map);
char	**ft_split(char *str, char C);
int		cont_letter(char *str, char C);
int		cont_words(char *str, char C);

#endif
