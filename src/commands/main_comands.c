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
	load_env(env);

	// TESTE ENV
	printf("\n\nTESTE ENV\n\n");
	char *PATH;

	ft_env();
	PATH = ft_getenv("PATH");
	printf("\n\nENTORNO PATH : %s\n\n", PATH);
	if (PATH)
		free(PATH);


	// TESTE EXPORT
	printf("\n\nTESTE EXPORT\n\n");
	ft_export("VARIABLE_NEW", "123456789*");
	ft_env();
	

	// TESTE UNSET
	printf("\n\nTESTE UNSET\n\n");
	ft_unset("VARIABLE_NEW");
	ft_env();

	// TESTE PWD
	printf("\n\nTESTE PWD\n\n");
	char *pwd = ft_pwd();
	printf("pwd: %s\n", pwd);
	if (pwd)
		free(pwd);


	// TESTE CD
	printf("\n\nTESTE CD\n\n");
	pwd = ft_getenv("PWD");
	printf("1 --> pwd: %s\n", pwd);
	if (pwd)
		free(pwd);
	ft_cd("..");
	pwd = ft_getenv("PWD");
	printf("2 --> pwd: %s\n", pwd);
	if (pwd)
		free(pwd);
	
	
	// TESTE ECHO
	printf("\n\nTESTE ECHO\n\n");
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

