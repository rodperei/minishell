/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:09:50 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/02 21:26:12 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_COMMAND_H
# define SIMPLE_COMMAND_H

# include "../../include/utils.h"
# include "../../include/comands.h"
# include "../../include/ft_limits.h"
# include "../../include/shell_functions.h"
# include "../../include/signal_minishel.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define INITIALIZE 0
# define CLOSE 1

void	execute_builtin(char **tokens, int has_pipe);
void	execute_binary(char **tokens);
void	execute_simple_command(char **tokens, int has_pipe);
void	build_cmd_path(char *cmd, char dir[PATH_MAX], char **paths);
void	check_path_var(char *cmd, char dir[PATH_MAX]);
void	compute_fds(int fds[REDIR_MAX], char mode);

#endif
