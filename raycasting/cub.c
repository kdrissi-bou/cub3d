/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 14:18:27 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	cast_rays(void)
{
	float	ray_angle;
	int		strip_id;

	
	strip_id = 0;
	ray_angle = g_player.angle - (FOV_ANGLE / 2);
	ray_angle = normalize_angle(ray_angle);
	while (strip_id < WIN_WIDTH)
	{
		cast_horz(ray_angle);
		cast_vert(ray_angle);
		store_rays(strip_id, ray_angle);
		ray_angle += FOV_ANGLE / WIN_WIDTH;
		ray_angle = normalize_angle(ray_angle);
		strip_id++;
	}
}

void	update(void)
{
	float	newPlayery;
	float	newPlayerx;

	g_player.angle += g_turn_direction * TURN_SPEED;
	newPlayery = g_player.y + sin(g_player.angle) * 25 * g_walk_direction;
	newPlayerx = g_player.x + cos(g_player.angle) * 25 * g_walk_direction;
	if (!(has_wall_at(newPlayerx, newPlayery)))
	{
		g_player.x += cos(g_player.angle) * WALK_SPEED * g_walk_direction;
	 	g_player.y += sin(g_player.angle) * WALK_SPEED * g_walk_direction;
	}
}

int		loop_key(void)
{
	g_img.img = mlx_new_image(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel, &g_img.line_length, &g_img.endian);
    update();
	cast_rays();
	render_walls();
	ft_sprite();
	if(!g_save)
	{
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_img.img, 0, 0);
		mlx_destroy_image(g_mlx.mlx, g_img.img);
	}
	return (0);
}

void	game(void)
{
	mlx_struct_init();
	init_player();
	init_sprite();
	init_rays();
	if (g_save)
		screen();
	mlx_hook(g_mlx.win, 2, 1L<<0, key_pressed, 0);
	mlx_hook(g_mlx.win, 3, 1L<<1, key_released, 0);
	mlx_loop_hook(g_mlx.mlx, loop_key, 0);
	mlx_hook(g_mlx.win, 17, (1L << 17), exit_success, 0);
	mlx_loop(g_mlx.mlx);
	
}

int		main(int argc, char **argv)
{	
	init();
	parsing(argc, argv);
	game();
}