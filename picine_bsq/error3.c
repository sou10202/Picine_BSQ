/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:09:24 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:11:05 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_col_num(char *buffer, int col_size)
{
	int	i;
	int	n;
	int	com_size;

	n = 0;
	i = skip_line(buffer, 0) + 1;
	if (buffer[i] == '\0')
	{
		print_error();
		return (-1);
	}
	while (buffer[i] != '\0' && n < row(buffer) - 1)
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		com_size = skip_line(buffer, i + 1) - i - 1;
		if (com_nb(col_size, com_size) == -1)
		{
			print_error();
			return (-1);
		}
		i++;
		n++;
	}
	return (0);
}

int	check_row_num(char *buffer)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			c++;
		i++;
	}
	if (c - 1 != row(buffer))
	{
		print_error();
		return (-1);
	}
	return (0);
}

int	ft_str_is_printable_re(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (1);
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			if ((!(str[i] >= 32 && str[i] <= 126)) && str[i] != '\n')
			{
				return (0);
			}
			else
				i++;
		}
		return (1);
	}
}

int	check_all_moji(char *buffer)
{
	char	*c;
	int		i;

	c = line1check(buffer);
	i = skip_line(buffer, 0) + 1;
	if (ft_str_is_printable_re(c) == 0 || ft_strlen(c) != 3)
	{
		print_error();
		return (-1);
	}
	while (buffer[i] != '\0')
	{
		if (!(buffer[i] == c[0] || buffer[i] == c[1] || buffer[i] == '\n'))
		{
			print_error();
			return (-1);
		}
		i++;
	}
	return (0);
}

int	error_check_all(char *buffer)
{
	char	*c;
	int		n;

	c = line1check(buffer);
	if (c == NULL || c[0] == -1 || c[1] == -1 || c[2] == -1)
		return (-1);
	n = check_all_moji(buffer);
	if (n == -1)
		return (-1);
	n = check_col_num(buffer, count_col_size(buffer));
	if (n == -1)
		return (-1);
	n = check_row_num(buffer);
	if (n == -1)
		return (-1);
	return (0);
}
