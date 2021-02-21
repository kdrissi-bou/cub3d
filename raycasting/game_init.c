/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:17:13 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 13:58:31 by drissi           ###   ########.fr       */
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
	if (!(g_sp_img.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->s,
	&g_sp_img.width, &g_sp_img.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_sp_img.buf = (int *)mlx_get_data_addr(g_sp_img.ptr,
	&g_sp_img.bpp,
	&g_sp_img.size_line,
	&g_sp_img.endian);
}

void	init_texture(void)
{
	if (!(g_no.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->no,
	&g_no.width, &g_no.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_no.buf = (int *)mlx_get_data_addr(g_no.ptr, &g_no.bpp,
	&g_no.size_line, &g_no.endian);
	if (!(g_so.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->so,
	&g_so.width, &g_so.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_so.buf = (int *)mlx_get_data_addr(g_so.ptr, &g_so.bpp,
	&g_so.size_line, &g_so.endian);
	if (!(g_we.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->we,
	&g_we.width, &g_we.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_we.buf = (int *)mlx_get_data_addr(g_we.ptr, &g_we.bpp,
	&g_we.size_line, &g_we.endian);
	if (!(g_ea.ptr = mlx_xpm_file_to_image(g_mlx.mlx, g_inputs->ea,
	&g_ea.width, &g_ea.height)))
		return (error("Error\nTexture file not found!\n", NULL));
	g_ea.buf = (int *)mlx_get_data_addr(g_ea.ptr, &g_ea.bpp,
	&g_ea.size_line, &g_ea.endian);
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
