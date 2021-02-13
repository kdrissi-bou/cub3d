/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/13 12:24:48 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		has_wall_at(float x, float y)
{
	int		mapX;
	int		mapY;

	mapX  = floor(x  / TILE_SIZE) ;
	mapY  = floor(y /TILE_SIZE);
	printf("%d, %d\n",mapY,mapX);
	if(mapX < 0 || mapX >= MAP_COLUMNS || mapY < 0 || mapY > MAP_ROWS)
		return (1);
	if(g_map[mapY][mapX] == '1')
		return (1);
	return (0);
	
}


void	cast_rays(void)
{
	float	ray_angle;
	int		strip_id;

	
	strip_id = 0;
	ray_angle = g_player.angle - (FOV_ANGLE / 2);
	ray_angle = normalize_angle(ray_angle);
	while(strip_id < WIN_WIDTH)
	{
		cast_horz(ray_angle);
		cast_vert(ray_angle);
		store_rays(strip_id, ray_angle);
		ray_angle = normalize_angle(ray_angle);
		ray_angle += FOV_ANGLE / WIN_WIDTH;
		strip_id++;
	}
}
void	update(void)
{
	float	newPlayery;
	float	newPlayerx;

	g_player.angle += g_turn_direction * TURN_SPEED;
	newPlayery = g_player.y + sin(g_player.angle) * WALK_SPEED * g_walk_direction;
	newPlayerx = g_player.x + cos(g_player.angle) * WALK_SPEED * g_walk_direction;
	if (!has_wall_at(newPlayerx, newPlayery))
	{
		g_player.x = newPlayerx;
	 	g_player.y = newPlayery;
	}
}

int		loop_key(void)
{
	int i;
	g_img.img = mlx_new_image(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel, &g_img.line_length, &g_img.endian);
    update();
	draw_map(); 
    draw_player(g_player.x, g_player.y, 5);
	cast_rays();
	while(i < 1)
	{
	 	draw_line(g_player.x, g_player.y, g_rays[i].wall_hit_x, g_rays[i].wall_hit_y, 0xFF0000 );
	 	i++;
	}
	 //draw_line(g_player.x, g_player.y, g_player.x + cos(g_player.angle) * 70, g_player.y + sin(g_player.angle) * 70, 0xFF0000);
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_img.img, 0, 0);
	mlx_destroy_image(g_mlx.mlx, g_img.img);
	return (0);
}

void	game(void)
{
	mlx_struct_init();
	init_player();
	init_rays();
	mlx_hook(g_mlx.win, 2, 1L<<0, key_pressed, 0);
	mlx_hook(g_mlx.win, 3, 1L<<1, key_released, 0);
	mlx_loop_hook(g_mlx.mlx, loop_key, 0);
	//loop_key();
    mlx_loop(g_mlx.mlx);
}


int		main(int argc, char **argv)
{	
	init();
	parsing(argc, argv);
	game();
}