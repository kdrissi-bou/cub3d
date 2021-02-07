/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:06:18 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/07 23:28:00 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_list	*g_head;

void	map_debut(void)
{
	g_head = g_file;
	while (g_head)
	{
		if (map_first_digit((char *)g_head->content))
			break ;
		g_head = g_head->next;
	}
}

void	map_size(void)
{
	t_list *temp;

	temp = g_head;
	while (temp)
	{
		if (map_first_digit(temp->content))
		{
			g_rows++;
			if (ft_strlen(temp->content) > (size_t)g_columns)
				g_columns = ft_strlen(temp->content);
		}
		else
			error("error map_size\n", NULL);
		temp = temp->next;
	}
	g_columns += 2;
}

void	map_filling(void)
{
	int	i;
	int	j;

	i = 1;
	if (!(g_map = (char **)malloc(sizeof(char *) * (g_rows + 1))))
		error("error map_second_init maloc", NULL);
	spacer();
	while (g_head)
	{
		j = 0;
		while (((char *)(g_head->content))[j])
		{
			g_map[i][j + 1] = ((char*)(g_head->content))[j];
			j++;
		}
		g_head = g_head->next;
		i++;
	}
	g_map[g_rows] = NULL;
}

void	map_errors(void)
{
	int		j;
	int		i;
	int		p;

	i = 1;
	p = 0;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_columns)
		{
			if (ft_strchr("NSWE", g_map[i][j]))
				p++;
			if (ft_strchr("0NSWE2", g_map[i][j]))
			{
				if (g_map[i - 1][j] == ' ' || g_map[i][j - 1] == ' ' ||
					g_map[i + 1][j] == ' ' || g_map[i][j + 1] == ' ')
					error("Error\n check spaces !\n", NULL);
			}
			else if (!(ft_strchr("0NSWE21 ", g_map[i][j])))
				error("Error\nMultiple or no players!\n", NULL);
		}
	}
	if (p != 1)
		error("error invalid number of players!\n", NULL);
}

void	map_treatment(void)
{
	map_debut();
	map_size();
	map_filling();
	map_errors();
}
