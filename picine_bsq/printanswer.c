/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printanswer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:50:13 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 20:29:53 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	to_print_ob(t_xy cnt, t_xy ans, int max_width)
{
	if (cnt.r > ans.r - max_width && cnt.r <= ans.r && cnt.c > ans.c - max_width
		&& cnt.c <= ans.c)
		return (1);
	return (0);
}

void	printans(char *fieldchar, char **field, int i, char **argv)
{
	t_xy	cnt;
	int		**w;
	t_xy	ans;
	int		max_w;
	t_xy	coord;

	coord = fillrowcol(i, argv);
	max_w = getlargest(coord, field, fieldchar);
	w = getlargestsquare(coord, field, fieldchar);
	ans = search_ans(coord, field, fieldchar);
	cnt.r = 0;
	while (cnt.r < coord.r)
	{
		cnt.c = 0;
		while (cnt.c < coord.c)
		{
			if (to_print_ob(cnt, ans, max_w))
				write(1, &fieldchar[2], 1);
			else
				write(1, &field[cnt.r][cnt.c], 1);
			cnt.c++;
		}
		write(1, "\n", 1);
		cnt.r++;
	}
}
