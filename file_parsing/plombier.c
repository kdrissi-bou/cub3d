/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plombier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:08:32 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 17:21:32 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error(char *err_msg, char **str)
{
	free_str_array(str);
	ft_lst_clear(&g_file);
	clean_up();
	ft_putstr_fd(err_msg, 2);
	exit(-1);
}

void	free_texture(void)
{
	if (g_mlx.mlx)
	{
		if (g_no.ptr)
			mlx_destroy_image(g_mlx.mlx, g_no.ptr);
		if (g_so.ptr)
			mlx_destroy_image(g_mlx.mlx, g_so.ptr);
		if (g_we.ptr)
			mlx_destroy_image(g_mlx.mlx, g_we.ptr);
		if (g_ea.ptr)
			mlx_destroy_image(g_mlx.mlx, g_ea.ptr);
	}
}

void	clean_up(void)
{
	free(g_inputs->no);
	free(g_inputs->so);
	free(g_inputs->we);
	free(g_inputs->ea);
	free(g_inputs->s);
	free(g_inputs);
	free_texture();
	free_str_array(g_map);
	free_sprite();
}

void	free_sprite(void)
{
	if (g_sp_img.ptr)
		mlx_destroy_image(g_mlx.mlx, g_sp_img.ptr);
	free(g_sprite);
}
