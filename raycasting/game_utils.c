/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:07:13 by drissi            #+#    #+#             */
/*   Updated: 2021/02/20 22:58:53 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

int		exit_success(void)
{
	clean_up();
	mlx_destroy_window(g_mlx.mlx, g_mlx.win);
	exit(0);
	return (0);
}

int		key_pressed(int key)
{
	if (key == KEY_ESC)
		exit_success();
	if (key == KEY_8 || key == KEY_UP)
		g_walk_direction = 1;
	if (key == KEY_2 || key == KEY_DOWN)
		g_walk_direction = -1;
	if (key == KEY_4 || key == KEY_LEFT)
		g_turn_direction = -1;
	if (key == KEY_6 || key == KEY_RIGHT)
		g_turn_direction = 1;
	return (0);
}

int		key_released(int key)
{
	if (key == KEY_8 || key == KEY_UP)
		g_walk_direction = 0;
	if (key == KEY_2 || key == KEY_DOWN)
		g_walk_direction = 0;
	if (key == KEY_4 || key == KEY_LEFT)
		g_turn_direction = 0;
	if (key == KEY_6 || key == KEY_RIGHT)
		g_turn_direction = 0;
	return (0);
}

int		distance(float x1, float y1, float x2, float y2)
{
	int		dis;

	dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (dis == 0)
		return (EPSILON);
	return (dis);
}
