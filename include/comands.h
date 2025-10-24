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

# define FILE_ENV "../../.env"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

// funcions
void	ft_exit(void);
int		ft_env(void);
int		ft_echo(char **args, char *text);
int		ft_export(char *name, char *value);
int		ft_unset(char *value);
int		ft_cd(char *path); // ainda tem problemas
char	*ft_pwd(void);
char	*ft_getcwd(void);

// env
char	*ft_getenv(char *name);
char	**ft_getallenv(void);
int		load_env(char **env);

// echo/echo.c
int		error(char *str);

#endif