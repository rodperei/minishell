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
#include "../include/comands.h"
#include "../include/helper_functions.h"
#include "../include/utils.h"

void	testeenvexportunset(void)
{
	char	*path;

	printf("\n\nTESTE ENV\n\n");
	ft_env();
	path = ft_getenv("PATH");
	printf("\n\nENTORNO PATH : %s\n\n", path);
	if (path)
		free(path);
	printf("\n\nTESTE EXPORT\n\n");
	ft_export("VARIABLE_NEW", "123456789*");
	ft_env();
	printf("\n\nTESTE UNSET\n\n");
	ft_unset("VARIABLE_NEW");
	ft_env();
}

void	testecd(void)
{
	char	*pwd;

	printf("\n\nTESTE CD\n\n");
	pwd = ft_getenv("PWD");
	printf("1 --> pwd: %s\n", pwd);
	if (pwd)
		free(pwd);
	ft_cd("../..");
	pwd = ft_getenv("PWD");
	printf("TEST: %s --> pwd: %s\n", "../..", pwd);
	if (pwd)
		free(pwd);
	ft_cd("./minishell/tests");
	pwd = ft_getenv("PWD");
	printf("TEST: %s --> pwd: %s\n", "./minishell/tests", pwd);
	if (pwd)
		free(pwd);
	ft_cd("/home/frnicola/sgoinfre/minishell");
	pwd = ft_getenv("PWD");
	printf("TEST: %s --> pwd: %s\n", "/home/frnicola/sgoinfre/minishell", pwd);
	if (pwd)
		free(pwd);
}

void	testeecho(void)
{
	printf("\n\nTESTE ECHO\n\n");
	ft_echo("Esto se va a imprimir PATH -> --$PATH--", 0);
	ft_echo("Esto se va a imprimir PATH -> --$PATH-- \n", 0);
}

int	main(int av, char **ac, char **env)
{
	load_env(env);
	testeenvexportunset();
	testecd();
	testeecho();
	ft_exit();
	len_all(ac);
	printf("%d", av);
}
