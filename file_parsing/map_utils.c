/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:24:31 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 16:14:47 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		map_first_digit(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
	{
		return (1);
	}
	return (0);
}

void	spacer(void)
{
	int	i;

	i = 0;
	while (i < g_rows)
	{
		if (!(g_map[i] = (char *)malloc(sizeof(char) * (g_columns + 1))))
			error("Error:\n allocation error", NULL);
		ft_memset(g_map[i], ' ', g_columns);
		g_map[i][g_columns] = '\0';
		i++;
	}
}

void	print_map(void)
{
	int i;

	i = 0;
	while (g_map[i])
	{
		printf("%s\n", g_map[i]);
		i++;
	}
}
