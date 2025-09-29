/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:12:55 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/13 14:12:57 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Este main es solo de teste
#include "../utils/utils.h"
#include "../../include/comands.h"

int	main(int av, char **ac, char **env)
{

	// TESTE ENV
	char *PATH;

	load_env(env);
	ft_env();
	PATH = ft_getenv("PATH");
	printf("\n\nENTORNO PATH : %s\n\n", PATH);
	if (PATH)
		free(PATH);


	// TESTE EXPORT
	ft_export("VARIABLE_NEW=123456789*");
	ft_env();
	

	
	// TESTE ECHO
	char *echo_var[2];

	echo_var[0] = "-n";
	echo_var[1] = NULL;
	echo(NULL, "Esto se va a imprimir PATH -> --$PATH--");
	echo(echo_var, "Esto se va a imprimir PATH -> --$PATH-- \n");


	// TESTE EXIT
	ft_exit();
	len_all(ac);
	printf("%d", av);
}

