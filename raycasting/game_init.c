/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:17:13 by drissi            #+#    #+#             */
/*   Updated: 2021/02/08 22:55:12 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(void)
{
	g_count	= 0;
	g_inputs = (t_cub3d *)malloc(sizeof(t_cub3d));
	g_inputs->we =NULL;
	g_inputs->ea =NULL;
	g_inputs->so =NULL;
	g_inputs->no =NULL;
	g_inputs->s =NULL;
	g_columns = 0;
	g_rows = 2;
	g_map = NULL;
}

void	player_init(void)
{
	g_player.x = WIN_WIDTH/2;
	g_player.y = WIN_HEIGHT/2;
	g_player.angle = normalize_angle(M_PI / 2);

}

void	mlx_struct_init(void)
{
	g_mlx.mlx_ptr = mlx_init();
	g_mlx.win_ptr = mlx_new_window(g_mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "kaw-kab");
	g_mlx.img_ptr = mlx_new_image(g_mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	//mlx_hook(g_mlx.win_ptr, 2, 0, key_pressed, 0);
	//mlx_hook(g_mlx.win_ptr, 3, 0, key_released, 0);
}