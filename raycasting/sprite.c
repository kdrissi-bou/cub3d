/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:18:25 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 13:57:48 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_sprite_sort(void)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < g_sprite_count)
	{
		j = 0;
		while (j < g_sprite_count - i - 1)
		{
			if (g_sprite[j].distance <= g_sprite[j + 1].distance)
			{
				tmp = g_sprite[j];
				g_sprite[j] = g_sprite[j + 1];
				g_sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	update_sprite(void)
{
	int		i;
	int		j;
	int		spt_id;

	spt_id = 0;
	j = -1;
	while (++j < ROWS)
	{
		i = -1;
		while (++i < COLUMNS)
		{
			if (g_map[j][i] == '2')
			{
				g_sprite[spt_id].y = (j * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[spt_id].x = (i * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[spt_id].distance = distance(
					g_sprite[spt_id].y, g_sprite[spt_id].x,
					g_player.y, g_player.x);
				spt_id++;
			}
		}
	}
	ft_sprite_sort();
}

void	render_sprite(int k, int x_fs, int y_fs, int sp_size)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	while (++i < sp_size)
	{
		if (x_fs + i < 0 || x_fs + i > WIN_WIDTH)
			continue ;
		if (x_fs + i < WIN_WIDTH)
			if (g_rays[x_fs + i].distance < g_sprite[k].distance)
				continue ;
		j = -1;
		while (++j < sp_size)
		{
			if (y_fs + j < 0 || y_fs + j > WIN_HEIGHT)
				continue ;
			color = g_sp_img.buf[g_sp_img.width * (j * g_sp_img.height
			/ sp_size) + (i * g_sp_img.width / sp_size)];
			if (color)
				put_pixel(&g_img, x_fs + i, y_fs + j, color);
		}
	}
}

void	sprite_traits(int spt_id)
{
	float	sp_angle;
	float	x_of;
	float	y_of;
	float	sp_size;

	sp_angle = atan2(-g_player.y + (g_sprite[spt_id].y),
							-g_player.x + (g_sprite[spt_id].x));
	while (sp_angle - g_player.angle > M_PI)
		sp_angle -= M_PI * 2;
	while (sp_angle - g_player.angle < -M_PI)
		sp_angle += M_PI * 2;
	sp_size = (WIN_WIDTH / g_sprite[spt_id].distance * TILE_SIZE);
	x_of = (sp_angle - g_player.angle) /
		RAD(60) * WIN_WIDTH + (WIN_WIDTH / 2 - sp_size / 2);
	y_of = (WIN_HEIGHT / 2 - sp_size / 2);
	render_sprite(spt_id, x_of, y_of, sp_size);
}

void	ft_sprite(void)
{
	int		i;

	update_sprite();
	i = -1;
	while (++i < g_sprite_count)
		sprite_traits(i);
}
