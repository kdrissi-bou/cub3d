/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:52:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/19 15:19:58 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT))
	{
		dst = img->addr + (y * img->line_length + x *
		(img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw_line(int x0, int y0, int x1, int y1, int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	xin;
	float	yin;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	xin = x0;
	yin = y0;
	i = 0;
	while (i < steps)
	{
		my_mlx_pixel_put(&g_img, xin, yin, color);
		xin += xinc;
		yin += yinc;
		i++;
	}
}

void	draw_square(int width, int height, int x, int y)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = x;
	while (i <= height)
	{
		k = x;
		j = 0;
		while (j <= width)
		{
			my_mlx_pixel_put(&g_img, k, y, 0xFFFFFF);
			k++;
			j++;
		}
		y++;
		i++;
	}
}

void	draw_map(void)
{
	int		i;
	int		j;
	float	mx;
	float	my;

	mx = 0;
	my = 0;
	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLUMNS)
		{
			if (g_map[i][j] == '1')
				draw_square(TILE_SIZE * MINI, TILE_SIZE * MINI, mx, my);
			mx += TILE_SIZE * MINI;
			j++;
		}
		mx = 0;
		my += TILE_SIZE * MINI;
		i++;
	}
}
