/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:01:12 by drissi            #+#    #+#             */
/*   Updated: 2021/02/13 03:18:40 by drissi           ###   ########.fr       */
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