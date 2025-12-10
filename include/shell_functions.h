/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:00:10 by rodperei          #+#    #+#             */
/*   Updated: 2025/12/02 20:44:37 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_FUNCTIONS_H
# define SHELL_FUNCTIONS_H

# include "./ft_limits.h"

# define RED     "\001\033[31m\002"
# define GREEN   "\001\033[32m\002"
# define YELLOW  "\001\033[33m\002"
# define BLUE    "\001\033[34m\002"
# define RESET   "\001\033[0m\002"
# define BOLD    "\001\033[1m\002"
# define HAS_PIPE 1
# define NOT_PIPE 0

char	*create_prompt(void);
char	**tokenize(char *input);
char	**expand(char **input);
char	**redirection(char **tokens, int fds[REDIR_MAX]);
void	execute_simple_command(char **tokens, int has_pipe);
void	compute_pipeline(char **tokens);
char	**parse(char **tokens);
char    **delete_space(char **tokens);

#endif
