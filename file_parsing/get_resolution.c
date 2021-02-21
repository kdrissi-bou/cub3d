/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:57:28 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 16:14:27 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_resolution(char *line)
{
	static int	dup = 0;
	char		**str;

	if (dup == 0)
	{
		str = ft_split(line + 1, ' ');
		if (line_is_digit(str) != 2)
			error("Error: Wrong resolution!", str);
		else
		{
			g_inputs->width = ft_atoi(str[0]);
			g_inputs->height = ft_atoi(str[1]);
			if (g_inputs->width == 0 || g_inputs->height == 0)
				error("Error:\nresolution too small or too big!", NULL);
			if (g_inputs->width > 2560 || g_inputs->width < 0)
				g_inputs->width = 2560;
			if (g_inputs->height > 1440 || g_inputs->height < 0)
				g_inputs->height = 1440;
			g_count++;
			free_str_array(str);
			dup = 1;
		}
	}
	else
		error("Error:\n something wrong in resolution!", NULL);
}
