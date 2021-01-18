/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/01/18 19:54:50 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

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
	int		mapIndexX;
	int		mapIndexY;
	
	newPlayery = g_player.y + sin(g_player.angle) * MOVEMENT_SPEED;
	newPlayerx = g_player.x + cos(g_player.angle) * MOVEMENT_SPEED;
	mapIndexX  = floor(newPlayerx / 24);
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
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		loop_key(void)
{
	// MLX HOOK
	// PUT IMAGE
	mlx_put_image_to_window(g_data.mlx_ptr, g_data.win_ptr, g_data.img_ptr, 0, 0);
	// if (has_wall_at() == 0)
	// {
	// 1 - TO DO : MAKE THE PLAYER MOVE ON X, Y AXIS DEPENDING ON THE ANGLE
		if (g_key.up == 1)
		{
	 	if (has_wall_at() == 0)
			{g_player.y += sin(g_player.angle) * MOVEMENT_SPEED;
			g_player.x += cos(g_player.angle) * MOVEMENT_SPEED;}
		}
		
		if (g_key.down == 1)
		{
			if (has_wall_at1() == 0)
			{g_player.y -= sin(g_player.angle) * MOVEMENT_SPEED;
			g_player.x -= cos(g_player.angle) * MOVEMENT_SPEED;}
		}
	// }
	// 2 - TO DO : MAKE MY PLAYER ROTATE
	if (g_key.left == 1)
		g_player.angle -= ROTATION_SPEED;
	if (g_key.right == 1)
		g_player.angle += ROTATION_SPEED;


    draw_map(0,0); // DRAW MAP
    draw_player(g_player.x, g_player.y, 5); // DRAW PLAYER
	draw_line(g_player.x, g_player.y,
	g_player.x + cos(g_player.angle) * 150, g_player.y + sin(g_player.angle) * 150, 0xFF0000);


	// 2 - TODO : THEN DO RAYCASTING

	// X - TODO : DESTROY AND CLEAR MY IMAGE (DO IT WHENEVER YOU WANT)
	return (0);
}

int		main(int argc, char **argv)
{

//Start by reading the .cub
	parsing(argc, argv);
    g_player.x = WIN_SIZE/2;
    g_player.y = WIN_SIZE/2;
    g_player.angle = normalize_angle(M_PI / 2);// PLAYER ANGLE
    g_data.mlx_ptr = mlx_init();
    g_data.win_ptr = mlx_new_window(g_data.mlx_ptr, WIN_SIZE, WIN_SIZE, "kaw-kab");
	g_data.img_ptr = mlx_new_image(g_data.mlx_ptr, WIN_SIZE, WIN_SIZE);
	mlx_hook(g_data.win_ptr, 2, 0, key_pressed, 0);
	mlx_hook(g_data.win_ptr, 3, 0, key_released, 0);

    draw_map(0,0);// DRAW MAP
    draw_player(g_player.x, g_player.y, 2);// DRAW PLAYER

	mlx_loop_hook(g_data.mlx_ptr, loop_key, 0);
    mlx_loop(g_data.mlx_ptr);
}