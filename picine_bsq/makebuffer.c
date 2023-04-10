/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makebuffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:06:18 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:31:56 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	cn_memori_size(char *filename)
{
	int		size;
	char	buf;
	int		fd;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (100);
	}
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

char	*read_file(int filen, char **argv)
{
	t_buff	buf;

	buf.size = cn_memori_size(argv[filen]);
	buf.buffer = malloc(sizeof(char) * (buf.size + 1));
	buf.fd = open(argv[filen], O_RDONLY);
	if (buf.fd == -1)
	{
		print_error();
		return (NULL);
	}
	buf.i = 0;
	while (buf.i < buf.size)
	{
		if (read(buf.fd, &buf.buffer[buf.i], 1) == -1)
		{
			print_error();
			return (NULL);
		}
		buf.i++;
	}
	buf.buffer[buf.i] = '\0';
	close(buf.fd);
	return (buf.buffer);
}

char	**makefield(int filen, char **argv)
{
	char	**field;
	char	*buffer;

	buffer = read_file(filen, argv);
	while (*buffer != '\n' && *buffer != '\0')
		buffer++;
	buffer++;
	field = ft_split(buffer, "\n");
	return (field);
}

t_xy	fillrowcol(int i, char **argv)
{
	t_xy	coord;
	char	*buff;

	buff = read_file(i, argv);
	coord.r = row(buff);
	coord.c = count_col_size(buff);
	return (coord);
}
