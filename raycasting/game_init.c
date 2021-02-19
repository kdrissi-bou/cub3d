/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:17:13 by drissi            #+#    #+#             */
/*   Updated: 2021/02/19 14:46:13 by kdrissi-         ###   ########.fr       */
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
	int		spt_id;

	spt_id = 0;
	if (!(g_sprite = malloc(sizeof(t_sprite *) * (g_sprite_count + 1))))
		return ;
	while (spt_id < g_sprite_count)
	{
		if (!(g_sprite[spt_id] = malloc(sizeof(t_sprite))))
			return ;
		if (!(g_sprite[spt_id]->ptr = mlx_xpm_file_to_image(g_mlx.mlx,
			g_inputs->s, &g_sprite[spt_id]->width, &g_sprite[spt_id]->height)))
			return (error("Error\nTexture file not found!\n", NULL));
		g_sprite[spt_id]->data = (int *)mlx_get_data_addr(g_sprite[spt_id]->ptr,
		&g_sprite[spt_id]->bpp,
		&g_sprite[spt_id]->size_line,
		&g_sprite[spt_id]->endian);
		spt_id++;
	}
	g_sprite[spt_id] = NULL;
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
	g_mlx.win = mlx_new_window(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "kaw-kab");
	g_img.img = mlx_new_image(g_mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel,
	&g_img.line_length, &g_img.endian);
}
