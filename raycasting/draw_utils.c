/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:52:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 14:12:02 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		g_i;
static int		g_dx;
static int		g_dy;

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT))
	{
		dst = img->addr + (y * img->line_length + x *
		(img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
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
			put_pixel(&g_img, k, y, 0xFFFFFF);
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

void	draw_line(int x0, int y0, int x1, int y1, int color)
{
	int		steps;
	float	xinc;
	float	yinc;
	float	xin;
	float	yin;

	g_dx = x1 - x0;
	g_dy = y1 - y0;
	steps = abs(g_dx) > abs(g_dy) ? abs(g_dx) : abs(g_dy);
	xinc = g_dx / (float)steps;
	yinc = g_dy / (float)steps;
	xin = x0;
	yin = y0;
	g_i = 0;
	while (g_i < steps)
	{
		put_pixel(&g_img, xin, yin, color);
		xin += xinc;
		yin += yinc;
		g_i++;
	}
}
