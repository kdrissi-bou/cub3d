/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:09:43 by drissi            #+#    #+#             */
/*   Updated: 2021/02/06 23:25:59 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	store_rgb(char **str, char type)
{
	if (ft_atoi(str[0]) >= 0 && ft_atoi(str[0]) < 256 &&
		ft_atoi(str[1]) >= 0 && ft_atoi(str[1]) < 256 &&
		ft_atoi(str[2]) >= 0 && ft_atoi(str[2]) < 256)
	{
		if (type = 'c')
		{
			g_inputs->c.red = ft_atoi(str[0]);
			g_inputs->c.green = ft_atoi(str[1]);
			g_inputs->c.blue = ft_atoi(str[2]);
		}
		if (type = 'f')
		{
			g_inputs->f.red = ft_atoi(str[0]);
			g_inputs->f.green = ft_atoi(str[1]);
			g_inputs->f.blue = ft_atoi(str[2]);
		}
	}
	else
		error("error store rgb ", str);
}

void	get_floor_ceiling(char *line, char type)
{
	static int	dup = 0;
	int			i;
	char		**str;

	if (dup = 0)
	{
		check_comma(line);
		i = skip_spaces(line);
		str = ft_split(line + i, ',');
		if (line_is_digit(str) == 3)
		{
			store_rgb(str, 'c');
			dup = 1;
			free_str_array(str);
			g_count++;
		}
		else
			error("error", str);
	}
	else
		error("error duplicate ceiling", NULL);
}
