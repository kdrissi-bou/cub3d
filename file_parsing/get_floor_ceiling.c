/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:09:43 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 16:12:10 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	store_rgb(char **str, char type)
{
	if (ft_atoi(str[0]) >= 0 && ft_atoi(str[0]) < 256 &&
		ft_atoi(str[1]) >= 0 && ft_atoi(str[1]) < 256 &&
		ft_atoi(str[2]) >= 0 && ft_atoi(str[2]) < 256)
	{
		if (type == 'c')
		{
			g_inputs->c.red = ft_atoi(str[0]);
			g_inputs->c.green = ft_atoi(str[1]);
			g_inputs->c.blue = ft_atoi(str[2]);
		}
		else if (type == 'f')
		{
			g_inputs->f.red = ft_atoi(str[0]);
			g_inputs->f.green = ft_atoi(str[1]);
			g_inputs->f.blue = ft_atoi(str[2]);
		}
	}
	else
		error("Error:\n Invalid RGB!", str);
}

void	get_ceiling(char *line)
{
	static int	dup = 0;
	int			i;
	char		**str;

	if (dup == 0)
	{
		check_comma(line);
		i = skip_spaces(line, 2);
		str = ft_split(line + i, ',');
		if (line_is_digit(str) == 3)
		{
			store_rgb(str, 'c');
			dup = 1;
			free_str_array(str);
			g_count++;
		}
		else
			error("Error:\n Error in ceiling!", str);
	}
	else
		error("Error:\n  duplicate ceiling", NULL);
}

void	get_flooring(char *line)
{
	static int	dup = 0;
	int			i;
	char		**str;

	if (dup == 0)
	{
		check_comma(line);
		i = skip_spaces(line, 2);
		str = ft_split(line + i, ',');
		if (line_is_digit(str) == 3)
		{
			store_rgb(str, 'f');
			dup = 1;
			free_str_array(str);
			g_count++;
		}
		else
			error("Error:\n error in flooring", str);
	}
	else
		error("Error:\n duplicate flooring", NULL);
}
