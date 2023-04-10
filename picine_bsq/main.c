/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:04:47 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:16:20 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **argv)
{
	char	**field;
	char	buff[1024];
	t_main	m;

	if (ac < 2)
		read(0, &buff, 1024);
	m.i = 1;
	while (m.i < ac)
	{
		m.buf = read_file(m.i, argv);
		if (m.buf == NULL || error_check_all(m.buf) == -1)
		{
			m.i++;
			continue ;
		}
		field = makefield(m.i, argv);
		m.fc = line1check(m.buf);
		printans(m.fc, field, m.i, argv);
		free(field);
		free(m.fc);
		free(m.buf);
		write(1, "\n", 1);
		m.i++;
	}
}
