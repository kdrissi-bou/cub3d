/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:01:12 by drissi            #+#    #+#             */
/*   Updated: 2021/02/26 21:22:59 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	set_angle(char player_pos)
{
	if (player_pos == 'N')
		g_player.angle = (270 * M_PI / 180);
	else if (player_pos == 'S')
		g_player.angle = (90 * M_PI / 180);
	else if (player_pos == 'W')
		g_player.angle = (180 * M_PI / 180);
	else if (player_pos == 'E')
		g_player.angle = (360 * M_PI / 180);
}

void	init(void)
{
	g_sprite_count = 0;
	g_sprite = NULL;
	g_count = 0;
	g_save = 0;
	g_inputs = (t_cub3d *)malloc(sizeof(t_cub3d));
	g_inputs->we = NULL;
	g_inputs->ea = NULL;
	g_inputs->so = NULL;
	g_inputs->no = NULL;
	g_inputs->s = NULL;
	g_no.ptr = NULL;
	g_so.ptr = NULL;
	g_we.ptr = NULL;
	g_ea.ptr = NULL;
	g_sp_img.ptr = NULL;
	g_rays = NULL;
	g_mlx.mlx = NULL;
	g_columns = 0;
	g_rows = 2;
	g_map = NULL;
}

int		has_wall_at(float x, float y)
{
	int		mapx;
	int		mapy;

	mapx = floor(x / TILE_SIZE);
	mapy = floor(y / TILE_SIZE);
	// printf("%d %d\n", mapx, mapy);
	if (mapx < 0 || mapx  > COLUMNS || mapy < 0 || mapy > ROWS)
		return (1);
if (g_map[mapy][mapx] == '1' || g_map[mapy][mapx] == ' ')
		return (1);
	return (0);
}
