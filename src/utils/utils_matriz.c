/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

char	**z_maloc_matriz(int size)
{
	char	**vec;

	vec = malloc(sizeof(char*) * (size + 1));
	while (size)
	{
		vec[size] = z_maloc(1);
		size--;
	}
	vec[0] = NULL;
	return (vec);
}

char	**append_matriz(char **matriz, char *new_line)
{
	int		aux;
	char	**result;

	if (!matriz)
		matriz = z_maloc_matriz(1);
	result = z_maloc_matriz(len_all(matriz) + 1);
	aux = 0;
	while (matriz && matriz[aux])
	{
		result[aux] = copy_vec(matriz[aux]);
		aux++;
	}
	result[aux] = copy_vec(new_line);
	result[aux + 1] = NULL;
	free_all(matriz);
	return (result);
}

char	**read_file(int fd, char c)
{
	char	*text;
	int		bt_read;
	char	*buf;
	char	**text_split;

	buf = z_maloc(SIZE_BUF);
	text = append(NULL, 1, buf);
	bt_read = read(fd, buf, SIZE_BUF);
	while (bt_read)
	{
		text = append(text, bt_read, buf);
		bt_read = read(fd, buf, SIZE_BUF);
	}
	close(fd);
	free (buf);
	text_split = ft_split(text, c);
	free(text);
	return (text_split);
}

int	count_caracter_matriz(char **mp, char c)
{
	int	ay;
	int	ax;
	int	result;

	ay = 0;
	ax = 0;
	result = 0;
	while (mp && mp[ay])
	{
		while (ax != len(mp[ay]))
		{
			if (mp[ay][ax] == c)
				result++;
			ax++;
		}
		ay++;
		ax = 0;
	}
	return (result);
}
