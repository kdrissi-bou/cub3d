/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:06:18 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/01/30 17:18:12 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		g_p;
static int		g_i;
static t_list	*g_temp;
static char		*g_str;

int     map_starts_here(char *line)
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

static void     first_init(void)
{
    
} 


void     map_treatment(void)
{
    while(g_file)
    {
        if(map_starts_here((char *)g_file->content))
            break;
        g_file = g_file->next;
    }
}