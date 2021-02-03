/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:06:18 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/03 17:11:03 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		g_p;
static int		g_i;
static t_list	*g_temp;

int     map_first_digit(char *line)
{
    int i = 0; 
    if(line[i] != '1' && line[i] != '0'&& line[i] != ' ')
        return(0);
    while(line[i] == ' ')
        i++;
    if(line[i] == '1'|| line[i] == '0')
        return(1);
    return(0);
}
void     map_debut(void)
{
    while(g_file)
    {
        if(map_first_digit((char *)g_file->content))
            break;
        g_file = g_file->next;
    }
}

static void     map_first_init(void)
{
    g_p = 0;
	g_columns = 0;
	g_rows = 0;
	g_temp = g_file;
} 
  
void    map_size(void)
{
    while (g_temp)
	{
		if (map_first_digit(g_temp->content))
		{
			g_rows++;
			if (ft_strlen(g_temp->content) > (size_t)g_columns)
				g_columns = ft_strlen(g_temp->content);
		}
		g_temp = g_temp->next;
	}
}
void    map_second_init(void)
{
    g_rows += 2;
    g_columns += 2;
	
	if (!(g_map = (char **)malloc(sizeof(char *) * (g_rows + 1))))
		return ;
	ft_memset(g_map[0],' ',g_columns);      
	g_i = 1;
}

void    map_filling(void)
{
    while (g_file)
	{
        ft_me   mset(g_map[i],'')
		if (map_first_digit(g_file->content))
			g_map[g_i++] = spacer(g_file->content, g_columns);
		g_file = g_file->next;
	}
	g_map[g_i++] = ft_memset(g_map[g_i],' ',g_columns);  
	g_map[g_i] = NULL;
}



int				map_errors(void)
{
	int		j;

	g_i = 0;
	while (++g_i < g_rows)
	{
		j = -1;
		while (++j < g_columns)
		{
			if (g_map[g_i][j] == 'N' || g_map[g_i][j] == 'S'|| g_map[g_i][j] == 'W' || g_map[g_i][j] == 'E')
				g_p++;
			if (g_map[g_i][j] == '0' || g_map[g_i][j] == 'N' || g_map[g_i][j] == 'S' || g_map[g_i][j] == 'W' || g_map[g_i][j] == 'E' || g_map[g_i][j] == '2')
			{
				if (g_map[g_i - 1][j] == ' ' || g_map[g_i][j - 1] == ' ' || g_map[g_i + 1][j] == ' ' || g_map[g_i][j + 1] == ' ')
					error("Error\nMultiple or no players or Invalid map!\n");
			}
			else if (g_map[g_i][j] != '0' && g_map[g_i][j] != 'N' && g_map[g_i][j] != 'S' && g_map[g_i][j] != 'W' && g_map[g_i][j] != 'E'&& g_map[g_i][j] != '2' && g_map[g_i][j] != '1' && g_map[g_i][j] != ' ')
				error("Error\nMultiple or no players or Invalid map!\n");
		}
	}
	return (0);
}

void    map_treatment(void)
{
    map_debut();
    map_first_init();
    map_size();
    map_second_init();
    map_filling();
    free_list();
    map_errors();
}