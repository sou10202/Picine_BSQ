/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:08:47 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:22:58 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*line1check(char *buff)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(sizeof(char) * 4);
	if (buff[0] == '0')
	{
		print_error();
		return (NULL);
	}
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n' && i >= 4)
		set_char(c, buff, i - 4);
	c[4] = '\0';
	if (c[0] == c[1] || c[1] == c[2] || c[2] == c[0] || i < 4)
	{
		print_error();
		return (NULL);
	}
	return (c);
}

int	skip_line(char *buffer, int i)
{
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	count_col_size(char *buffer)
{
	int	i;
	int	size;
	int	diff;

	i = skip_line(buffer, 0);
	diff = i;
	i = skip_line(buffer, i + 1);
	size = i - diff - 1;
	return (size);
}
