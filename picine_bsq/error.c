/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:10:26 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:22:41 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	com_nb(int a, int b)
{
	if (a == b)
		return (0);
	else
		return (-1);
}

int	set_nb(char *buffer, int i, int flag)
{
	int	nb;
	int	n;

	nb = 0;
	n = 0;
	if (flag == 1)
	{
		while (n < i - 3)
		{
			nb = nb * 10 + (buffer[n] - '0');
			n++;
		}
	}
	else
	{
		while (buffer[n] != '\0' && buffer[n] >= '0' && buffer[n] <= '9')
		{
			nb = nb * 10 + (buffer[n] - '0');
			n++;
		}
	}
	return (nb);
}

int	row(char *buffer)
{
	int	i;
	int	n;
	int	nb;

	i = 0;
	n = 0;
	while (buffer[i] != '\0' && buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	if (buffer[i] == '\n' && i >= 4)
		nb = set_nb(buffer, i, 1);
	else
		nb = set_nb(buffer, i, 0);
	return (nb);
}

int	set_char(char *c, char *buff, int i)
{
	if (buff[i + 1] == '\0')
	{
		print_error();
		return (-1);
	}
	c[0] = buff[i + 1];
	if (buff[i + 2] == '\0')
	{
		print_error();
		return (-1);
	}
	c[1] = buff[i + 2];
	if (buff[i + 3] == '\0')
	{
		print_error();
		return (-1);
	}
	c[2] = buff[i + 3];
	return (0);
}
