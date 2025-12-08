/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:51:29 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/29 17:56:25 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "../../include/utils.h"
#include "../../include/ft_limits.h"
#include "redirections.h"

#define TRUNCATE 0
#define APPEND 1
#define BUFFER_SIZE 1000

char	**redir_input(char **tokens, int *i, int *fd)
{
	*fd = open(tokens[*i + 1], O_RDONLY);
	if (*fd == -1)
	{
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDIN_FILENO);
	return (remove_redir_tokens(tokens, i));
}

char	**redir_output(char **tokens, int *i, int *fd, char mode)
{
	int		flags;
	mode_t	permitions;

	flags = O_WRONLY | O_CREAT | O_APPEND;
	if (mode == TRUNCATE)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	permitions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	*fd = open(tokens[*i + 1], flags, permitions);
	if (*fd == -1)
	{
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
		exit(EXIT_FAILURE);
	}
	dup2(*fd, STDOUT_FILENO);
	return (remove_redir_tokens(tokens, i));
}

char	*load_buffer(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	char	*input;
	int		ret;

	input = 0;
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE - 1);
		if (ret == -1)
			error_handle(0, 0);
		buf[ret] = '\0';
		tmp = ft_strjoin(input, buf);
		free(input);
		input = tmp;
	}
	return (input);
}

char	**redir_heredoc(char **tokens, int *i)
{
	char	*buf;
	int		fd;
	char	name[65];

	ft_memmove(name, "./", ft_strlen("./") + 1);
	ft_strlcat(name, tokens[*i + 1], 65);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		error_handle(0, 0);
	buf = load_buffer(fd);
	close(fd);
	unlink(name);
	write(STDIN_FILENO, buf, ft_strlen(buf));
	free(buf);
	return (remove_redir_tokens(tokens, i));
}

char	**redirection(char **tokens, int fds[REDIR_MAX])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (tokens[++i])
	{
		if (j >= REDIR_MAX)
			error_handle(0, "Exceeded redirections limit\n");
		if (equal(tokens[i], "<"))
			tokens = redir_input(tokens, &i, &fds[++j]);
		else if (equal(tokens[i], ">"))
			tokens = redir_output(tokens, &i, &fds[++j], TRUNCATE);
		else if (equal(tokens[i], ">>"))
			tokens = redir_output(tokens, &i, &fds[++j], APPEND);
		else if (equal(tokens[i], "<<"))
			tokens = redir_heredoc(tokens, &i);
	}
	return (tokens);
}
