/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:32:25 by drissi            #+#    #+#             */
/*   Updated: 2021/02/27 00:42:36 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	g_i;
static int	g_y;

void	draw_ceiling(int i, int top)
{
	int	color;

	g_y = 0;
	color = rgb_to_int(g_inputs->c.red, g_inputs->c.green,
	g_inputs->c.blue);
	while(g_y < top)
	{
		put_pixel(i,g_y,color);
		g_y++;
	}

}

void	draw_flooring(int i, int bottom)
{
	int	color;
	
	color = rgb_to_int(g_inputs->f.red, g_inputs->f.green,
	g_inputs->f.blue);
	g_y = bottom;
	while(g_y < g_inputs->height)
	{
		put_pixel(i,g_y,color);
		g_y++;
	}
}

int		rgb_to_int(int r, int g, int b)
{
	return ((r * (256 * 256)) + (g * (256)) + (b));
}

void	draw_wall(int i, int top_pixel, int wall_height)
{
	int		dis_from_top;
	int		of_x;
	int		of_y;

	g_y = top_pixel;
	of_x = g_rays[i].was_hit_vert ? (int)g_rays[i].wall_hit_y % TILE_SIZE :
	(int)g_rays[i].wall_hit_x % TILE_SIZE;
	while (g_y < (top_pixel + wall_height))
	{
		dis_from_top = g_y + (wall_height / 2) - (g_inputs->height / 2);
		of_y = dis_from_top * ((float)TEX_HEIGHT / wall_height);
		if ((TEX_WIDTH * of_y + of_x) > 0)
		{
			if (g_rays[i].up && !g_rays[i].was_hit_vert)
				put_pixel( i, y, g_so.buf[(g_so.width * of_y) + of_x]);
			else if (g_rays[i].down && !g_rays[i].was_hit_vert)
					put_pixel( i, y, g_no.buf[(g_no.width * of_y) + of_x]);
			else if (g_rays[i].right && g_rays[i].was_hit_vert)
				put_pixel( i, y, g_we.buf[(g_we.width * of_y) + of_x]);
			else if (g_rays[i].left && g_rays[i].was_hit_vert)
				put_pixel( i, y, g_ea.buf[(g_ea.width * of_y) + of_x]);
		}
		put_pixel( i, g_y, g_ea.buf[(g_ea.width * of_y) + of_x]);
		g_y++;
	}
}

void	render_walls(void)
{
	float		wall_height;
	float		distance_plane;
	float		wall_top_pixel;
	float		wall_bottom_pixel;
	float		perp_distance;

	g_i = 0;
	distance_plane = (g_inputs->width / 2) / tan((60 * (M_PI / 180)) / 2);
	while (g_i < g_inputs->width)
	{
		perp_distance = g_rays[g_i].distance *
		cos(g_rays[g_i].ray_angle - g_player.angle);
		wall_height = (TILE_SIZE / perp_distance) * distance_plane;
		wall_top_pixel = (g_inputs->height / 2) - (wall_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		wall_bottom_pixel = wall_top_pixel + wall_height;
		wall_bottom_pixel = wall_bottom_pixel > g_inputs->height ?
		g_inputs->height : wall_bottom_pixel;
		draw_ceiling(g_i, wall_top_pixel);
		draw_wall(g_i, wall_top_pixel, wall_height);
		draw_flooring(g_i, wall_bottom_pixel);
		g_i++;
	}
}
