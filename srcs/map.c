/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:06:18 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/01/27 19:27:21 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int     map_starts_here(char *line)
{
    int i = 0; 
    if(line[i] != '1'|| line[i] != '0'|| line[i] != ' ')
        return(0);
    while(line[i] == ' ')
        i++;
    if(line[i] == '1'|| line[i] == '0')
        return(1);
    return(0);
}


void     map_treatment(void)
{
    while(g_file)
    {
        if(map_starts_here((char *)g_file->content))
            break;
        g_file = g_file->next;
    }
    while (g_file)
    {
        if(!is_map((char *)g_file->content))
            error("ERROR : Wrong Map\n");
        g_file = g_file->next;    
    }
}

int is_map(char *line)
{
    
}