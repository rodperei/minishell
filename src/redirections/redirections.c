/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:16 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/24 15:59:20 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "../../include/utils.h"
#include "../../include/redirections.h"

void	case_redirection(char ***parse, int aux)
{
	int		fd;
	char	*path;

	fd = -2;
	path = ft_resuelve_path((*parse)[aux + 1]);
	if (equal((*parse)[aux], ">"))
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (equal((*parse)[aux], "<"))
		fd = open(path, O_RDONLY);
	else if (equal((*parse)[aux], ">>"))
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0 && fd != -2)
		error_handle(0, "Error in redireccion");
	if (fd != -2)
		close(fd);
	free(path);
}

char	*create_file_tem(int num, char *buf)
{
	char	*name;
	int		fd;

	fd = 0;
	name = ft_strdup("tem0");
	name[4] = (char)(33 + num);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		error_handle(0, "Error in redireccion >> not permison fd");
	write(fd, buf, ft_strlen(buf));
	close(fd);
	return (name);
}

void	case_read_term(char ***parse, int aux)
{
	char	*buf;
	char	*str;

	if (!equal((*parse)[aux], "<<"))
		return ;
	buf = NULL;
	while (1)
	{
		str = readline(">");
		if (!str || equal(str, (*parse)[aux + 1]))
			break ;
		str = append(str, ft_strlen("\n"), "\n");
		buf = append(buf, ft_strlen(str), str);
		free(str);
	}
	if (str)
		free(str);
	if (buf)
	{
		free((*parse)[aux + 1]);
		(*parse)[aux + 1] = create_file_tem(aux, buf);
	}
}

void	redirection(char ***parse)
{
	int			aux;

	aux = -1;
	while ((*parse)[++aux])
	{
		//case_redirection(parse, aux);
		case_read_term(parse, aux);
	}
	print_matriz_vec((*parse), "REDIRRECION");
}
