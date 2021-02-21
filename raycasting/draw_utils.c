/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:52:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 18:35:32 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		g_i;
static int		g_dx;
static int		g_dy;

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < g_inputs->width && y >= 0 && y < g_inputs->height))
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
		put_pixel(&g_img, xin, yin, line.color);
		xin += xinc;
		yin += yinc;
		g_i++;
	}
}
