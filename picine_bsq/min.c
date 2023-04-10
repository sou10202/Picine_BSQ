/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:27:29 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 23:12:37 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
}

int	check_min(int **w, t_xy cnt)
{
	int	i;

	i = min(w[cnt.r - 1][cnt.c - 1], w[cnt.r - 1][cnt.c], w[cnt.r][cnt.c - 1])
		+ 1;
	return (i);
}
