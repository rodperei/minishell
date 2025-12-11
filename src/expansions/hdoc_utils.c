/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:55:49 by rodperei          #+#    #+#             */
/*   Updated: 2025/11/29 12:56:29 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <readline/readline.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../../include/utils.h"
#include "../../include/ft_limits.h"

#define TMP_FILE "tmp"

char	*read_input(char *delimiter)
{
	char	*str;
	char	*tmp;
	char	*buff;

	str = "";
	buff = 0;
	while (1)
	{
		str = readline(">");
		if (!str || equal(str, delimiter))
			break ;
		tmp = ft_strjoin(str, "\n");
		free(str);
		str = ft_strjoin(buff, tmp);
		free(buff);
		free(tmp);
		buff = str;
	}
	return (buff);
}

void	save_buffer(char *buff, int	*j)
{
	char	name[66];
	char	*file_no;
	mode_t	permitions;
	int		fd;

	if (*j > HDOC_MAX)
		error_handle(0, "Exceeded maximum Here-Document number\n");
	ft_memmove(name, TMP_FILE, ft_strlen(TMP_FILE) + 1);
	file_no = ft_itoa(*j);
	ft_strlcat(name, file_no, 66);
	free(file_no);
	permitions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd = open(name, O_WRONLY | O_CREAT, permitions);
	write(fd, buff, ft_strlen(buff));
	free(buff);
	close(fd);
}
