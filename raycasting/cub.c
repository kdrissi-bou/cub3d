/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/09 00:08:31 by drissi           ###   ########.fr       */
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
/*
// MAKE MY KEY VAR TO 1
int		key_pressed(int key)
{
	if (key == UP_ARROW)
		g_key.up = 1;
	if (key == DW_ARROW)
		g_key.down = 1;
	if (key == LF_ARROW)
		g_key.left = 1;
	if (key == RT_ARROW)
		g_key.right = 1;
	return (0);
}

// WILL SET KEY VARS TO 0
int		key_released(int key)
{
	if (key == UP_ARROW)
		g_key.up = 0;
	if (key == DW_ARROW)
		g_key.down = 0;
	if (key == LF_ARROW)
		g_key.left = 0;
	if (key == RT_ARROW)
		g_key.right = 0;
	return (0);
}
// WALL COLLISION PART	
int		has_wall_at()
{
	float	newPlayerx;
	float	newPlayery;
	//float		mapIndexX;

	
	newPlayery = g_player.y + sin(g_player.angle) * MOVEMENT_SPEED;
	newPlayerx = g_player.x + cos(g_player.angle) * MOVEMENT_SPEED;
	//mapIndexX  = floor(newPlayerx / 24);
	// mapIndexY  =
	
	if(newPlayerx < 0 ||newPlayerx > WIN_SIZE || newPlayery < 0 || newPlayery > WIN_SIZE)
		return (1);
	return(0);
	
}

int		has_wall_at1()
{
	float	newPlayerx;
	float	newPlayery;
	newPlayery = g_player.y - sin(g_player.angle) * MOVEMENT_SPEED;
	newPlayerx = g_player.x - cos(g_player.angle) * MOVEMENT_SPEED;
	
	if(newPlayerx < 0 ||newPlayerx > WIN_SIZE || newPlayery < 0 || newPlayery > WIN_SIZE)
		return (1);
	
	return(0);
	
}


int		loop_key(void)
{
	mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win_ptr, g_mlx.img_ptr, 0, 0);
	if (g_key.up == 1)
	{
	 	if (has_wall_at() == 0)
		{
			g_player.y += sin(g_player.angle) * MOVEMENT_SPEED;
			g_player.x += cos(g_player.angle) * MOVEMENT_SPEED;}
		}
	if (g_key.down == 1)
	{
		if (has_wall_at1() == 0)
		{
			g_player.y -= sin(g_player.angle) * MOVEMENT_SPEED;
			g_player.x -= cos(g_player.angle) * MOVEMENT_SPEED;
		}
	}
	if (g_key.left == 1)
		g_player.angle -= ROTATION_SPEED;
	if (g_key.right == 1)
		g_player.angle += ROTATION_SPEED;
    draw_map(0,0); // DRAW MAP
    draw_player(g_player.x, g_player.y, 5); // DRAW PLAYER
	// draw_line(g_player.x, g_player.y, g_player.x + cos(g_player.angle) * 150, g_player.y + sin(g_player.angle) * 150, 0xFF0000);


	// 2 - TODO : THEN DO RAYCASTING

	// X - TODO : DESTROY AND CLEAR MY IMAGE (DO IT WHENEVER YOU WANT)
	return (0);
}
*/
void	game(void)
{
	//player_init();
	mlx_struct_init();
	//print_map();
    draw_map();
	//draw_square(20, 20, 0, 220);

    //draw_player(g_player.x, g_player.y, 2);
	//mlx_loop_hook(g_mlx.mlx_ptr, loop_key, 0);
    mlx_loop(g_mlx.mlx_ptr);
}

int		main(int argc, char **argv)
{	
	init();
	parsing(argc, argv);
	game();
}