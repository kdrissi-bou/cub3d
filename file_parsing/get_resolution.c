/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:57:28 by drissi            #+#    #+#             */
/*   Updated: 2021/02/08 18:50:09 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_resolution(char *line)
{
	static int	dup = 0;
	char		**str;
	int			x;
	int			y;

	x = 1370;
	y = 720;
	if (dup == 0)
	{
		/*mlx_get_screen_size(g_mlx.mlx_ptr, &x, &y);*/
		str = ft_split(line + 1, ' ');
		if (line_is_digit(str) != 2)
			error("Error: Wrong resolution!", str);
		else
		{
			g_inputs->width = ft_atoi(str[0]) > x ? x : ft_atoi(str[0]);
			g_inputs->height = ft_atoi(str[1]) > y ? y : ft_atoi(str[1]);
			g_count++;
			free_str_array(str);
			dup = 1;
		}
	}
	else
		error("ok", NULL);
}
