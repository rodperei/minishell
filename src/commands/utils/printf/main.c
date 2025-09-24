/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:25:07 by frnicola          #+#    #+#             */
/*   Updated: 2025/06/21 19:25:09 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prints(va_list *vargs, char form)
{
	int		cont;

	cont = 0;
	if (form == 'c' && ++cont)
		put_char(va_arg(*vargs, int));
	else if (form == 's')
		cont += put_str(va_arg(*vargs, char *));
	else if (form == 'p')
		cont += put_hex_sing(va_arg(*vargs, unsigned long), 0);
	else if (form == 'd' || form == 'i')
		cont += put_num(va_arg(*vargs, int), 0);
	else if (form == 'u')
		cont += put_uni(va_arg(*vargs, unsigned), 0);
	else if (form == 'x' || form == 'X')
		cont += put_hex(va_arg(*vargs, unsigned long), form == 'X', 0);
	else if (form == '%' && ++cont)
		put_char(form);
	return (cont);
}

int	ft_printf(char const *format, ...)
{
	int		cont;
	va_list	vargs;

	va_start (vargs, format);
	cont = 0;
	while (format && *format)
	{
		if (*format == '%' && format++)
			cont += prints(&vargs, *format);
		else
		{
			put_char(*format);
			cont++;
		}
		format++;
	}
	va_end(vargs);
	return (cont);
}
/*
int		main(void)
{
	int	mio;
	int	orig;

	mio = ft_printf("%c\n", '0');
	orig = printf("%c\n", '0');
	printf(" mio: %i | orig: %i \n\n", mio, orig);

	mio = ft_printf("%s\n", "hola");
	orig = printf("%s\n", "hola");
	printf(" mio: %i | orig: %i \n\n", mio, orig);

	mio = ft_printf("%i\n", -1230456);
	orig = printf("%i\n", -1230456);
	printf(" mio: %i | orig: %i \n\n", mio, orig);

	mio = ft_printf("%d\n", 123);
	orig = printf("%d\n", 123);
	printf(" mio: %i | orig: %i \n\n", mio, orig);

	mio = ft_printf("%p\n", (void*)987987987);
	orig = printf("%p\n", (void*)987987987);
	printf(" mio: %i | orig: %i\n\n", mio, orig);

	mio = ft_printf("%u\n", -50);
	orig = printf("%u\n", -50);
	printf(" mio: %i | orig: %i\n\n", mio, orig);

	mio = ft_printf("%x\n",10);
	orig = printf("%x\n",10);
	printf(" mio: %i | orig: %i\n\n", mio, orig);

	mio = ft_printf("%X\n",10);
	orig = printf("%X\n",10);
	printf(" mio: %i | orig: %i\n\n", mio, orig);
}
*/