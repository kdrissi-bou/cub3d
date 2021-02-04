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
static t_list	*g_head;

int     map_first_digit(char *line)
{
    int i = 0; 
    if(line[i] != '1' && line[i] != '0'&& line[i] != ' ')
        return(0);
    while(line[i] == ' ')
        i++;
    if(line[i] == '1'|| line[i] == '0')
    {
        return(1);
    }
    return(0);
}
void    map_debut(void)
{
    g_head = g_file;
    while(g_head)
    {
        if(map_first_digit((char *)g_head->content))
            break;
        g_head = g_head->next;
    }
}

static void     map_first_init(void)
{
    g_p = 0;
	g_columns = 0;
	g_rows = 2;
} 
  
void    map_size(void)
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
            error("error map_size\n");
		temp = temp->next;
	}
}

void    map_second_init(void)
{
    g_columns += 2;
	
	if (!(g_map = (char **)malloc(sizeof(char *) * (g_rows + 1))))
		error("error map_second_init maloc");
}

void    spacer(void)
{
    int     i;
    i   =   0;
    while(i <= g_rows)
        {
            if (!(g_map[i] = (char *)malloc(sizeof(char) * (g_columns + 1))))
		        error("error spacer\n");
            ft_memset(g_map[i], ' ', g_columns);
            g_map[i][g_columns + 1] = '\0';
            i++;
        } 
}

void    map_filling(void)
{ 
    int i;
    i = 1;
    spacer();
    
    while (g_head)
	{
		g_map[i] = ft_memcpy(g_map[i] + 1, g_head->content,ft_strlen(g_map[i]));
		g_head = g_head->next;
        i++;
	}
	g_map[i] = NULL;
}



int				map_errors(void)
{
	int		j;
    int     i;

	i = 0;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_columns)
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'S'|| g_map[i][j] == 'W' || g_map[i][j] == 'E')
				g_p++;
			if (g_map[i][j] == '0' || g_map[i][j] == 'N' || g_map[i][j] == 'S' || g_map[i][j] == 'W' || g_map[i][j] == 'E' || g_map[i][j] == '2')
			{
				if (g_map[i - 1][j] == ' ' || g_map[i][j - 1] == ' ' || g_map[i + 1][j] == ' ' || g_map[i][j + 1] == ' ')
					error("Error\nMultiple or no players or Invalid map!\n");
			}
			else if (g_map[i][j] != '0' && g_map[i][j] != 'N' && g_map[i][j] != 'S' && g_map[i][j] != 'W' && g_map[i][j] != 'E'&& g_map[i][j] != '2' && g_map[i][j] != '1' && g_map[i][j] != ' ')
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
    //free_list();
    map_errors();
}