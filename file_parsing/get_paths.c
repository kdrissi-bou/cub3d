/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:35:59 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 16:13:45 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_north(char *line)
{
	static int	dup = 0;

	if (dup == 1)
		error("Error:\nduplicate north", NULL);
	if (line_is_empty(line + 3))
		error("Error:\nNo path provided", NULL);
	g_inputs->no = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
	dup = 1;
	g_count++;
}

void	get_west(char *line)
{
	static int	dup = 0;

	if (dup == 1)
		error("Error:\nduplicate west", NULL);
	if (line_is_empty(line + 3))
		error("Error:\nNo path provided", NULL);
	g_inputs->we = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
	dup = 1;
	g_count++;
}

void	get_east(char *line)
{
	static int	dup = 0;

	if (dup == 1)
		error("Error:\n duplicate east", NULL);
	if (line_is_empty(line + 3))
		error("Error:\nNo path provided", NULL);
	g_inputs->ea = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
	dup = 1;
	g_count++;
}

void	get_south(char *line)
{
	static int	dup = 0;

	if (dup == 1)
		error("Error:\nduplicate south", NULL);
	if (line_is_empty(line + 3))
		error("Error:\nNo path provided", NULL);
	g_inputs->so = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
	dup = 1;
	g_count++;
}

void	get_sprite(char *line)
{
	static int	dup = 0;

	if (dup == 1)
		error("Error:\nduplicate sprite", NULL);
	if (line_is_empty(line + 2))
		error("Error:\nNo path provided", NULL);
	g_inputs->s = ft_substr(line, skip_spaces(line, 2), ft_strlen(line));
	dup = 1;
	g_count++;
}
