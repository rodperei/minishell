/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:18:13 by rodperei          #+#    #+#             */
/*   Updated: 2025/09/26 09:54:51 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/helper_functions.h"
#include "../../include/comands.h"
#include "../../include/utils.h"

static char	*wrap_path(char *path)
{
	char	*home;
	char	*wrapped_path;

	home = ft_getenv("HOME");
	if (!home || ft_strncmp(path, home, ft_strlen(home)))
		return (path);
	wrapped_path = ft_strjoin("~", &path[ft_strlen(home)]);
	if (!wrapped_path)
		return (path);
	free(path);
	if (home)
		free(home);
	return (wrapped_path);
}

static void	get_hostname(char *hostname)
{
	int	fd;
	int	read_ret;

	fd = open("/etc/hostname", O_RDONLY);
	if (fd == -1)
		perror("prompt.c:41:10: in function 'get_hostname'");
	read_ret = read(fd, hostname, 253);
	if (read_ret == -1)
		perror("prompt.c:47:10: in function 'get_hostname'");
	ft_replace(hostname, '.', '\0');
	if (read_ret < 253)
		hostname[read_ret - 1] = '\0';
	if (close(fd) == -1)
		perror("prompt.c:52:10: in function 'get_hostname'");
}

static char	*merge_vars(char *hostname, char *path)
{
	char	*user;
	char	*tmp1;
	char	*tmp2;

	user = ft_getenv("USER");
	if (!user)
		user = "";
	tmp2 = ft_strjoin(user, "@");
	tmp1 = ft_strjoin(tmp2, hostname);
	free(tmp2);
	tmp2 = ft_strjoin(tmp1, ":");
	free(tmp1);
	tmp1 = ft_strjoin(tmp2, path);
	free(tmp2);
	free(path);
	tmp2 = ft_strjoin(tmp1, "$ ");
	free(tmp1);
	if (user)
		free(user);
	return (tmp2);
}

char	*add_colors(char *pront)
{
	char	*tem;
	char	*tem1;

	tem1 = ft_strjoin(GREEN, pront);
	free(pront);
	tem = ft_strjoin(BOLD, tem1);
	free(tem1);
	return (append(tem, ft_strlen(tem) + ft_strlen(RESET), RESET));
}

char	*create_prompt(void)
{
	char	*prompt;
	char	hostname[254];
	char	*path;
	int		i;

	path = ft_getcwd();
	if (!path)
	{
		perror("prompt.c:63:10: in function 'create_prompt'");
		return (NULL);
	}
	path = wrap_path(path);
	i = -1;
	while (++i < 254)
		hostname[i] = '\0';
	get_hostname(hostname);
	prompt = merge_vars(hostname, path);
	prompt = add_colors(prompt);
	return (prompt);
}
