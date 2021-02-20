/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:17:13 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 00:42:03 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_rays(void)
{
	if (!(g_rays = malloc(sizeof(t_rays) * (WIN_WIDTH))))
		return ;
}

void	init_sprite(void)
{
	if (!(g_sprite = malloc(sizeof(t_sprite) * (g_sprite_count + 1))))
		return ;
	if (!(g_sp_img.ptr= mlx_xpm_file_to_image(g_mlx.mlx,g_inputs->s,
	&g_sp_img.width, &g_sp_img.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_sp_img.buffer = (int *)mlx_get_data_addr(g_sp_img.ptr,
	&g_sp_img.bpp,
	&g_sp_img.size_line,
	&g_sp_img.endian);
}

void	init_texture(void)
{
	if (!(g_north.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->no,
	&g_north.width, &g_north.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_north.buffer = (int *)mlx_get_data_addr(g_north.ptr, &g_north.bpp,
	&g_north.size_line, &g_north.endian);
	if (!(g_south.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->so,
	&g_south.width, &g_south.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_south.buffer = (int *)mlx_get_data_addr(g_south.ptr, &g_south.bpp,
	&g_south.size_line, &g_south.endian);
	if (!(g_west.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->we,
	&g_west.width, &g_west.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_west.buffer = (int *)mlx_get_data_addr(g_west.ptr, &g_west.bpp,
	&g_west.size_line, &g_west.endian);
	if (!(g_east.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->ea,
	&g_east.width, &g_east.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_east.buffer = (int *)mlx_get_data_addr(g_east.ptr, &g_east.bpp,
	&g_east.size_line, &g_east.endian);
}

void	init_player(void)
{
	int	i;
	int	j;

	g_sprite_count = 0;
	i = 1;
	while (i < ROWS - 1)
	{
		j = 1;
		while (j < COLUMNS - 1)
		{
			if (ft_strchr("NSWE", g_map[i][j]))
			{
				set_angle(g_map[i][j]);
				g_player.y = ((i) * TILE_SIZE) + TILE_SIZE / 2;
				g_player.x = ((j) * TILE_SIZE) + TILE_SIZE / 2;
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
	init_texture();
	if (!g_save)
		g_mlx.win = mlx_new_window(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
}
