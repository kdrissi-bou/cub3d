/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/15 02:48:23 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		has_wall_at(float x, float y)
{
	int		mapX;
	int		mapY;

	mapX  = floor(x  / TILE_SIZE) ;
	mapY  = floor(y /TILE_SIZE);
	if(mapX < 0 || mapX > MAP_COLUMNS || mapY < 0 || mapY > MAP_ROWS)
		return (1);
	if(g_map[mapY][mapX] == '1')
		return (1);
	return (0);
}
void	draw_ceiling(int i, int	top)
{
	int	color;
	color = rgb_to_int(g_inputs->c.red,g_inputs->c.green,g_inputs->c.blue);
	draw_line(i,0,i,top,color);

}
void	draw_flooring(int i, int bottom)
{
	int	color;
	color = rgb_to_int(g_inputs->f.red,g_inputs->f.green,g_inputs->f.blue);
	draw_line(i,bottom,i,WIN_HEIGHT,color);

}
int		rgb_to_int(int r, int g, int b)
{
	return ((r * (256 * 256)) + (g * (256)) + (b));
}

void	render_walls(void)
{
	int	wall_height;
	float	distance_plane;
	float	projected_wall_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	float	perp_distance;
	int i;
	// int y;
	i = 0;
	while (i < WIN_WIDTH)
	{
		
		distance_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
		perp_distance = g_rays[i].distance * cos(g_rays[i].ray_angle - g_player.angle);
		//printf("%f, %f\n", g_rays[i].distance,cos(g_rays[i].ray_angle - g_player.angle) );
		projected_wall_height = (TILE_SIZE / perp_distance) * distance_plane;
		wall_height = (int)projected_wall_height;
		wall_top_pixel = (WIN_HEIGHT / 2) - (wall_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		wall_bottom_pixel = (WIN_HEIGHT / 2) + (wall_height / 2);
		//printf("%d, %d\n", wall_height, wall_top_pixel);
		wall_bottom_pixel = wall_bottom_pixel > WIN_HEIGHT ? WIN_HEIGHT : wall_bottom_pixel;
		draw_ceiling(i,wall_top_pixel);
		draw_line(i, wall_top_pixel, i, wall_bottom_pixel,0xFFFFFF);
		//draw_flooring(i,wall_bottom_pixel);
		i++;
	}
	
}
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
		draw_line(g_player.x  * MINI, g_player.y * MINI, g_rays[strip_id].wall_hit_x * MINI, g_rays[strip_id].wall_hit_y * MINI, 0xFFF00 );
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
	g_img.img = mlx_new_image(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel, &g_img.line_length, &g_img.endian);
    update();
	// draw_map(); 
    // draw_player(g_player.x * MINI, g_player.y * MINI, 5* MINI);
	cast_rays();
	render_walls();
	cast_rays();
	draw_map(); 
    draw_player(g_player.x * MINI, g_player.y * MINI, 5* MINI);
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