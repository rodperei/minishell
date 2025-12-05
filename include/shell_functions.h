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

#ifndef HELPER_FUNCTIONS_H
# define HELPER_FUNCTIONS_H

# include "./ft_limits.h"

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define RESET	"\033[0m"
# define BOLD	"\033[1m"

char	*create_prompt(void);
char	**tokenize(char *input);
char	**expand(char **input);
char	**redirection(char **tokens, int fds[REDIR_MAX]);
void	execute_simple_command(char **tokens);
void	compute_pipeline(char **tokens);
char	**parse(char **tokens);

#endif
