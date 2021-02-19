/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:01:12 by drissi            #+#    #+#             */
/*   Updated: 2021/02/19 14:46:21 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	set_angle(char player_pos)
{
	if (player_pos == 'N')
		g_player.angle = RAD(270);
	else if (player_pos == 'S')
		g_player.angle = RAD(90);
	else if (player_pos == 'W')
		g_player.angle = RAD(180);
	else if (player_pos == 'E')
		g_player.angle = RAD(360);
}

void	init(void)
{
	g_count = 0;
	g_inputs = (t_cub3d *)malloc(sizeof(t_cub3d));
	g_inputs->we = NULL;
	g_inputs->ea = NULL;
	g_inputs->so = NULL;
	g_inputs->no = NULL;
	g_inputs->s = NULL;
	g_columns = 0;
	g_rows = 2;
	g_map = NULL;
}
