/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   later.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:19:36 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 18:47:03 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_player(int x0, int y0, int radius)
{
	int x;
	int y;
	int x_change;
	int y_change;
	int radius_error;
	int	i;
	int j;

	x = radius;
	y = 0;
	x_change = 1 - (radius << 1);
	y_change = 0;
	radius_error = 0;
	i = x0 - x;
	j = x0 - y;
	while (x >= y)
	{
		while (i <= x0 + x)
		{
			put_pixel(&g_img, i, y0 + y, 0xFFFF00);
			put_pixel(&g_img, i, y0 - y, 0xFFFF00);
			i++;
		}
		while (j <= x0 + y)
		{
			put_pixel(&g_img, i, y0 + x, 0xFFFF00);
			put_pixel(&g_img, i, y0 - x, 0xFFFF00);
			j++;
		}
		y++;
		radius_error += y_change;
		y_change += 2;
		if (((radius_error << 1) + x_change) > 0)
		{
			x--;
			radius_error += x_change;
			x_change += 2;
		}
	}
}

void	print_map(void)
{
	int i;

	i = 0;
	while (g_map[i])
	{
		printf("%s\n", g_map[i]);
		i++;
	}
}
