/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maxwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:24 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:25:12 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**w_mall(t_xy coord)
{
	int		**w;
	t_xy	cnt;

	w = malloc(sizeof(int *) * coord.r);
	if (w == NULL)
		return (NULL);
	cnt.r = 0;
	while (cnt.r < coord.r)
	{
		w[cnt.r] = malloc(sizeof(int) * coord.c);
		if (w[cnt.r] == NULL)
			return (NULL);
		cnt.c = 0;
		while (cnt.c < coord.c)
		{
			w[cnt.r][cnt.c] = 1;
			cnt.c++;
		}
		cnt.r++;
	}
	return (w);
}

int	**to_fill_0(t_xy coord, char **field, char *fieldchar)
{
	int		**w;
	t_xy	cnt;

	w = w_mall(coord);
	cnt.r = 0;
	cnt.c = 0;
	while (cnt.c < coord.c)
	{
		if (field[0][cnt.c] == fieldchar[1])
			w[0][cnt.c] = 0;
		cnt.c++;
	}
	while (cnt.r < coord.r)
	{
		if (field[cnt.r][0] == fieldchar[1])
			w[cnt.r][0] = 0;
		cnt.r++;
	}
	return (w);
}

int	getlargest(t_xy coord, char **field, char *fieldchar)
{
	int		**w;
	t_xy	cnt;
	int		max_w;

	w = to_fill_0(coord, field, fieldchar);
	cnt.r = 1;
	max_w = 0;
	while (cnt.r < coord.r)
	{
		cnt.c = 1;
		while (cnt.c < coord.c)
		{
			if (field[cnt.r][cnt.c] == fieldchar[1])
				w[cnt.r][cnt.c] = 0;
			else
			{
				w[cnt.r][cnt.c] = check_min(w, cnt);
				max_w = MAX(max_w, w[cnt.r][cnt.c]);
			}
			cnt.c++;
		}
		cnt.r++;
	}
	free(w);
	return (max_w);
}

int	**getlargestsquare(t_xy coord, char **field, char *fieldchar)
{
	int		**w;
	t_xy	cnt;
	int		max_w;

	w = to_fill_0(coord, field, fieldchar);
	cnt.r = 1;
	max_w = 0;
	while (cnt.r < coord.r)
	{
		cnt.c = 1;
		while (cnt.c < coord.c)
		{
			if (field[cnt.r][cnt.c] == fieldchar[1])
				w[cnt.r][cnt.c] = 0;
			else
			{
				w[cnt.r][cnt.c] = check_min(w, cnt);
				max_w = MAX(max_w, w[cnt.r][cnt.c]);
			}
			cnt.c++;
		}
		cnt.r++;
	}
	return (w);
}

t_xy	search_ans(t_xy coord, char **field, char *fieldchar)
{
	int		**w;
	int		max_width;
	t_xy	cnt;

	w = getlargestsquare(coord, field, fieldchar);
	max_width = getlargest(coord, field, fieldchar);
	cnt.r = 0;
	while (cnt.r < coord.r)
	{
		cnt.c = 0;
		while (cnt.c < coord.c)
		{
			if (w[cnt.r][cnt.c] == max_width)
				return (cnt);
			cnt.c++;
		}
		cnt.r++;
	}
	free(w);
	return (cnt);
}
