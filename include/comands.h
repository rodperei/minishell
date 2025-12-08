/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:12:55 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/13 14:12:57 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMANDS_H
# define COMANDS_H

# define FILE_ENV "/tmp/.env_minishell"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

// funcions
void	ft_exit(int status);
void	last_exit(void);
int		ft_env(void);
int		ft_echo(char *text, int flag_n);
int		ft_export(char *name, char *value);
int		ft_export_num(char *name, int num);
void	ft_export_void(void);
int		valid_name_export(char *str);
int		ft_unset(char *value);
int		ft_cd(char *path);
char	*ft_pwd(void);
char	*ft_getcwd(void);

// env
char	*ft_getenv(char *name);
char	**ft_getallenv(void);
int		load_env(char **env);

// simple_commans
int		is_builtin(char **tokens);

// traductor.v
void	ft_echo_tokens(char **tokens);
void	ft_cd_tokens(char **tokens, int has_pipe);
void	ft_export_tokens(char **tokens, int has_pipe);
void	ft_unset_tokens(char **tokens, int has_pipe);
void	ft_pwd_tokens(void);
void	ft_env_tokens(void);
void	ft_exit_tokens(char **tokens, int has_pipe);

#endif
