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

// funcions
void	ft_exit();
int		ft_env();
int		ft_echo(char **args, char *text);
int		ft_export(char *name, char *value);
int		ft_unset(char *value);
int		ft_cd(char *path); // ainda tem problemas
char	*ft_pwd(void);

// env
char	*ft_getenv(char *name);
char	**ft_getallenv();
int		load_env(char **env);

// echo/echo.c
int		error(char *str);

#endif