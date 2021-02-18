/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:17:13 by drissi            #+#    #+#             */
/*   Updated: 2021/02/18 01:43:22 by drissi           ###   ########.fr       */
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
	// mlx_struct_init();
}
void	init_rays(void)
{
	if (!(g_rays = malloc(sizeof(t_rays) * (WIN_WIDTH))))
		return ;
}

void	init_texture(void)
{
	
	if (!(g_north.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->no, &g_north.img_width, &g_north.img_height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_north.buffer = (int *)mlx_get_data_addr(g_north.ptr, &g_north.bpp, &g_north.size_line, &g_north.endian);
	
	if (!(g_south.buffer = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->so, &g_south.img_width, &g_south.img_height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_south.buffer = (int *)mlx_get_data_addr(g_south.buffer, &g_south.bpp, &g_south.size_line, &g_south.endian);
	
	if (!(g_west.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->we,&g_west.img_width, &g_west.img_height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_west.buffer = (int *)mlx_get_data_addr(g_west.ptr, &g_west.bpp, &g_west.size_line, &g_west.endian);
	
	if (!(g_east.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->ea, &g_east.img_width, &g_east.img_height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_east.buffer = (int *)mlx_get_data_addr(g_east.ptr, &g_east.bpp, &g_east.size_line, &g_east.endian);
}

void	init_player(void)
{
	int i;
	int j;
	g_sprite_count = 0;
	
	i = 1;
	while (i < MAP_ROWS -1)
	{
		j = 1;
		while (j < MAP_COLUMNS-1)
		{
			if (ft_strchr("NSWE", g_map[i][j]))
			{
				set_angle(g_map[i][j]);
				g_player.y = ((i ) * TILE_SIZE) + TILE_SIZE / 2;
				g_player.x = ((j ) * TILE_SIZE) + TILE_SIZE / 2;
				//printf("%d,%d\n",i,j);
			}
			else if (g_map[i][j] == '2')
				g_sprite_count++;
			j++;
		}
		i++;
	}
}

void	mlx_struct_init(void)
{
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "kaw-kab");
	g_img.img = mlx_new_image(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel, &g_img.line_length, &g_img.endian);

}