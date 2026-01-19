/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:12:55 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/13 14:12:57 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../../include/signal_minishel.h"

void	handler_ctrl_c(int sing)
{
	int	aux;

	(void)(sing);
	wait(&aux);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handler_ctrl_c_father(int sing)
{
	(void)(sing);
	exit(0);
}

void	signal_main(void)
{
	signal(SIGINT, handler_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_father(void)
{
	signal(SIGINT, handler_ctrl_c_father);
	signal(SIGQUIT, handler_ctrl_c_father);
}

void	signal_son(void)
{
	signal(SIGINT, handler_ctrl_c_father);
	signal(SIGQUIT, handler_ctrl_c_father);
}
