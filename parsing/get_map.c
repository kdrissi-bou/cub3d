/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:06:18 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/07 00:02:02 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		g_p;
static t_list	*g_head;

void    print_map(void)
{
    int i = 0;
    while(g_map[i])
    {
        printf("%s\n",g_map[i]);
        i++;
    }
}
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
            error("error map_size\n", NULL);
		temp = temp->next;
	}
}

void    map_second_init(void)
{
    g_p = 0;
    g_columns += 2;
	
	if (!(g_map = (char **)malloc(sizeof(char *) * (g_rows + 1))))
		error("error map_second_init maloc",NULL);
}

void    spacer(void)
{
    int     i;
    i   =   0;
    while(i <= g_rows)
        {
            if (!(g_map[i] = (char *)malloc(sizeof(char) * (g_columns + 1))))
		        error("error spacer\n",NULL);
            ft_memset(g_map[i], ' ', g_columns);
            g_map[i][g_columns + 1] = '\0';
            i++;
        } 
}

void    map_filling(void)
{ 
    int i;
    int j;
    i = 1;


    spacer();
    while (g_head)
	{
        j = 0;
		while (((char *)(g_head->content))[j])
        {
            g_map[i][j+1] = ((char*)(g_head->content))[j];

            j++;
        }
    
		g_head = g_head->next;
        i++;
	}
    g_map[g_rows] = NULL;
}



int				map_errors(void)
{
	int		j;
    int     i;

	i = 1;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_columns)
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'S'|| g_map[i][j] == 'W' || g_map[i][j] == 'E')
				g_p++;
			if (ft_strchr("0NSWE2",g_map[i][j]))
			{
				if (g_map[i - 1][j] == ' ' || g_map[i][j - 1] == ' ' || g_map[i + 1][j] == ' ' || g_map[i][j + 1] == ' ')
                {  printf("%d %d\n",i,j);
					error("Error\n check spaces !\n", NULL);
                }
			}
			else if (!(ft_strchr("0NSWE21 ",g_map[i][j])))
            {
                printf("%c %d %d",g_map[i][j],i,j);
				error("Error\nMultiple or no players or Invalid map!\n", NULL);
            }
		}
	}
	return (0);
}

void    map_treatment(void)
{
    map_debut();;
    map_size();
    map_second_init();
    map_filling();
    print_map();
    map_errors();
}