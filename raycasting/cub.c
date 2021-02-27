/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:23:53 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/27 00:30:19 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cast_rays(void)
{
	float	ray_angle;
	int		strip_id;
	float	fov_angle;

	strip_id = 0;
	fov_angle = (60 * M_PI / 180);
	ray_angle = g_player.angle - (30 * M_PI / 180);
	ray_angle = normalize_angle(ray_angle);
	while (strip_id < g_inputs->width)
	{
		g_ray.down = ray_angle > 0 && ray_angle < M_PI;
		g_ray.up = !g_ray.down;
		g_ray.right = ray_angle < (M_PI / 2) || ray_angle > (1.5 * M_PI);
		g_ray.left = !g_ray.right;
		cast_horz(ray_angle);
		cast_vert(ray_angle);
		store_rays(strip_id, ray_angle);
		ray_angle = normalize_angle(ray_angle);
		ray_angle += fov_angle / g_inputs->width;
		strip_id++;
	}
}

void	update(void)
{
	float	new_playery;
	float	new_playerx;

	g_player.angle += g_turn_direction * TURN_SPEED;
	new_playery = g_player.y + sin(g_player.angle) * 50 * g_walk_direct;
	new_playerx = g_player.x + cos(g_player.angle) * 50 * g_walk_direct;
	if (!(has_wall_at(new_playerx, new_playery)))
	{
		g_player.x += cos(g_player.angle) * 7 * g_walk_direct;
		g_player.y += sin(g_player.angle) * 7 * g_walk_direct;
	}
}

int		loop_key(void)
{
	g_img.img = mlx_new_image(g_mlx.mlx, g_inputs->width, g_inputs->height);
	g_img.addr = (int *)mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel,
	&g_img.line_length, &g_img.endian);
	update();
	cast_rays();
	render_walls();
	ft_sprite();
	if (!g_save)
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
	mlx_hook(g_mlx.win, 2, 1L << 0, key_pressed, 0);
	mlx_hook(g_mlx.win, 3, 1L << 1, key_released, 0);
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
