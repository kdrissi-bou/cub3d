/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:01:18 by drissi            #+#    #+#             */
/*   Updated: 2021/02/18 10:38:28 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_vert(float ray_angle)
{
	g_ray.vert_hit = FALSE;
	g_ray.x_inter = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	g_ray.x_inter	+= g_ray.right ? TILE_SIZE : 0;
	g_ray.y_inter = g_player.y + (g_ray.x_inter - g_player.x) * tan(ray_angle);
	g_ray.xstep = TILE_SIZE;
	g_ray.xstep *= g_ray.left ? -1 : 1;
	g_ray.ystep  =  TILE_SIZE * tan(ray_angle);
	g_ray.ystep *= (g_ray.up && g_ray.ystep > 0) ? -1 : 1;
	g_ray.ystep *= (g_ray.down && g_ray.ystep < 0) ? -1 : 1;
	g_ray.next_vert_X = g_ray.x_inter;
	g_ray.next_vert_Y = g_ray.y_inter;
}
void	cast_vert(float ray_angle)
{
	init_vert(ray_angle);
	while(g_ray.next_vert_X >=0 && g_ray.next_vert_X <= MAP_COLUMNS * TILE_SIZE && g_ray.next_vert_Y >= 0 && g_ray.next_vert_Y <= MAP_ROWS * TILE_SIZE)
	{
		g_ray.check_X = g_ray.next_vert_X + (g_ray.left ? -1 : 0);
		g_ray.check_Y = g_ray.next_vert_Y ;
		if(has_wall_at(g_ray.check_X, g_ray.check_Y))
		{
			g_ray.vert_hit = TRUE;
			g_ray.x_hit_vert = g_ray.next_vert_X;
			g_ray.y_hit_vert = g_ray.next_vert_Y;
			break ;
		}
		else
		{
			g_ray.next_vert_X += g_ray.xstep;
			g_ray.next_vert_Y += g_ray.ystep;
		}
	}
}
int		distance(float x1, float y1, float x2, float y2)
{
	int		dis;

	dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 -  y1));
	if (dis == 0)
		return (EPSILON);
	return(dis);
}
void	init_horz(float ray_angle)
{
	g_ray.horz_hit = FALSE;
	g_ray.down = ray_angle > 0 && ray_angle < M_PI;
	g_ray.up = !g_ray.down;
	g_ray.right = ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI);
	g_ray.left = !g_ray.right;
	g_ray.y_inter = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	g_ray.y_inter	+= g_ray.down ? TILE_SIZE : 0;
	g_ray.x_inter = g_player.x + (g_ray.y_inter - g_player.y) / tan(ray_angle);
	g_ray.ystep = TILE_SIZE;
	g_ray.ystep *= g_ray.up ? -1 : 1;
	g_ray.xstep  =  TILE_SIZE / tan(ray_angle);
	g_ray.xstep *= (g_ray.left && g_ray.xstep > 0) ? -1 : 1;
	g_ray.xstep *= (g_ray.right && g_ray.xstep < 0) ? -1 : 1;
	g_ray.next_horz_X = g_ray.x_inter;
	g_ray.next_horz_Y = g_ray.y_inter;
	
}
void	cast_horz(float	ray_angle)
{

	init_horz(ray_angle);

	while(g_ray.next_horz_X >=0 && g_ray.next_horz_X <= MAP_COLUMNS * TILE_SIZE && g_ray.next_horz_Y >= 0 && g_ray.next_horz_Y <= MAP_ROWS * TILE_SIZE)
	{
		g_ray.check_X = g_ray.next_horz_X;
		g_ray.check_Y = g_ray.next_horz_Y + (g_ray.up ? -1 : 0);
		if (has_wall_at(g_ray.check_X, g_ray.check_Y))
		{
			g_ray.x_hit_horz = g_ray.next_horz_X;
			g_ray.y_hit_horz = g_ray.next_horz_Y;
			g_ray.horz_hit = 1;
			break;
		}
		else
		{
			g_ray.next_horz_X += g_ray.xstep;
			g_ray.next_horz_Y += g_ray.ystep;
		}
	}
}
void	store_rays(int strip_id, float ray_angle)
{
	g_ray.horz_distance = g_ray.horz_hit ? distance(g_player.x, g_player.y, g_ray.x_hit_horz, g_ray.y_hit_horz) : INT_MAX;
	g_ray.vert_distance = g_ray.vert_hit ? distance(g_player.x, g_player.y, g_ray.x_hit_vert, g_ray.y_hit_vert) : INT_MAX;
	g_rays[strip_id].distance = fmin(g_ray.horz_distance, g_ray.vert_distance);
	g_rays[strip_id].wall_hit_x = (g_ray.horz_distance < g_ray.vert_distance)
		? g_ray.x_hit_horz : g_ray.x_hit_vert;
	g_rays[strip_id].wall_hit_y = (g_ray.horz_distance < g_ray.vert_distance)
		? g_ray.y_hit_horz : g_ray.y_hit_vert;
	g_rays[strip_id].was_hit_vert = (g_ray.vert_distance < g_ray.horz_distance)
		? TRUE : FALSE;
	g_rays[strip_id].ray_angle = ray_angle;
	g_rays[strip_id].down = ray_angle > 0 && ray_angle < M_PI;
	g_rays[strip_id].up =  !g_rays[strip_id].down;
	g_rays[strip_id].right = ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI);
	g_rays[strip_id].left = !g_rays[strip_id].right;

}