/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_heders.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:25:07 by frnicola          #+#    #+#             */
/*   Updated: 2025/06/21 19:25:09 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int		put_hex(unsigned int hex, int mayus, int itera);
int		put_uni(unsigned int num, int itera);
int		put_str(char *s);
int		prints(va_list *vargs, char form);
int		ft_printf(char const *format, ...);
int		put_num(int num, int itera);
int		put_hex_sing(unsigned long hex, int itera);
void	put_char(unsigned char c);

#endif