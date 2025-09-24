/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
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

# define SIZE_BUF 300

//	lens.c
int		len(char *str);
int		len_all(char **str);
int		equal(char *str, char *str1);
int		equaln(char *str, char *str1, int size);

// utils_vec.c
char	*copy_vec(char *str);
char	*z_maloc(int size);
char	*append(char *vec, int size_new, char *buff);
int		count_caracter(char *mp, char c);

// utils_matriz.c
char	**z_maloc_matriz(int size);
char	**append_matriz(char **matrz, char *new_line);
int		count_caracter_matriz(char **mp, char c);
char	**read_file(int fd, char c);

// ft_split.c
void	free_all(char **map);
char	**ft_split(char *str, char C);
int		cont_letter(char *str, char C);
int		cont_words(char *str, char C);

#endif
