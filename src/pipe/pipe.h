/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/11/29 17:56:41 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../../include/ft_limits.h"
# include "../../include/utils.h"
# include "../../include/shell_functions.h"
# include "../../include/comands.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	pipe_io(int in, int out);
void	close_pipe(int p_fd[PIPE_MAX][2], int cant);
void	init_pipe(int p_fd[PIPE_MAX][2], int cant);

#endif