/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:52:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/27 00:27:42 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		g_i;
static int		g_dx;
static int		g_dy;

void	put_pixel(int x, int y, int color)
{
	if ((x >= 0 && x < g_inputs->width && y >= 0 && y < g_inputs->height))
		g_img.addr[(x + (y * g_inputs->width))] = color;
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
			put_pixel( k, y, 0xFFFFFF);
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

void	draw_line(t_line line)
{
	int		steps;
	float	xinc;
	float	yinc;
	float	xin;
	float	yin;

	g_dx = line.x1 - line.x0;
	g_dy = line.y1 - line.y0;
	steps = abs(g_dx) > abs(g_dy) ? abs(g_dx) : abs(g_dy);
	xinc = g_dx / (float)steps;
	yinc = g_dy / (float)steps;
	xin = line.x0;
	yin = line.y0;
	g_i = 0;
	while (g_i < steps)
	{
		put_pixel( xin, yin, line.color);
		xin += xinc;
		yin += yinc;
		g_i++;
	}
}
