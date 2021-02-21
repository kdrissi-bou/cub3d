/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:32:25 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 18:46:37 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int g_i;

void	draw_ceiling(int i, int top)
{
	t_line	line;

	line.color = rgb_to_int(g_inputs->c.red, g_inputs->c.green,
	g_inputs->c.blue);
	line.x0 = i;
	line.y0 = 0;
	line.x1 = i;
	line.y1 = top;
	draw_line(line);
}

void	draw_flooring(int i, int bottom)
{
	t_line	line;

	line.color = rgb_to_int(g_inputs->f.red, g_inputs->f.green,
	g_inputs->f.blue);
	line.x0 = i;
	line.y0 = bottom;
	line.x1 = i;
	line.y1 = g_inputs->height;
	draw_line(line);
}

int		rgb_to_int(int r, int g, int b)
{
	return ((r * (256 * 256)) + (g * (256)) + (b));
}

void	draw_wall(int i, int top_pixel, int wall_height)
{
	int		y;
	int		dis_from_top;
	int		of_x;
	int		of_y;

	y = top_pixel;
	of_x = g_rays[i].was_hit_vert ? (int)g_rays[i].wall_hit_y % TILE_SIZE :
	(int)g_rays[i].wall_hit_x % TILE_SIZE;
	while (y < (top_pixel + wall_height))
	{
		dis_from_top = y + (wall_height / 2) - (g_inputs->height / 2);
		of_y = dis_from_top * ((float)TEX_HEIGHT / wall_height);
		if ((i >= 0 && i < g_inputs->width && y >= 0 && y < g_inputs->height))
		{
			if (g_rays[i].up && !g_rays[i].was_hit_vert)
				put_pixel(&g_img, i, y, g_so.buf[(g_so.width * of_y) + of_x]);
			else if (g_rays[i].down && !g_rays[i].was_hit_vert)
				put_pixel(&g_img, i, y, g_no.buf[(g_no.width * of_y) + of_x]);
			else if (g_rays[i].right && g_rays[i].was_hit_vert)
				put_pixel(&g_img, i, y, g_we.buf[(g_we.width * of_y) + of_x]);
			else if (g_rays[i].left && g_rays[i].was_hit_vert)
				put_pixel(&g_img, i, y, g_ea.buf[(g_ea.width * of_y) + of_x]);
		}
		y++;
	}
}

void	render_walls(void)
{
	int		wall_height;
	float	distance_plane;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	float	perp_distance;

	g_i = 0;
	distance_plane = (g_inputs->width / 2) / tan((60 * (M_PI / 180)) / 2);
	while (g_i < g_inputs->width)
	{
		perp_distance = g_rays[g_i].distance *
		cosf(g_rays[g_i].ray_angle - g_player.angle);
		wall_height = (int)((TILE_SIZE / perp_distance) * distance_plane);
		wall_top_pixel = (g_inputs->height / 2) - (wall_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		wall_bottom_pixel = (g_inputs->height / 2) + (wall_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > g_inputs->height ?
		g_inputs->height : wall_bottom_pixel;
		draw_ceiling(g_i, wall_top_pixel);
		draw_wall(g_i, wall_top_pixel, wall_height);
		draw_flooring(g_i, wall_bottom_pixel);
		g_i++;
	}
}
