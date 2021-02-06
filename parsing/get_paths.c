/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:35:59 by drissi            #+#    #+#             */
/*   Updated: 2021/02/06 22:26:32 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"


void    get_north(char *line)
{
    static int  dup = 0;
    if(dup == 1)
        error("error: duplicate north",NULL);
    g_inputs->no = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
    dup = 1;
    g_count++;
}

void    get_west(char *line)
{
    static int  dup = 0;
    if(dup == 1)
        error("error: duplicate west",NULL);
    g_inputs->we = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
    dup = 1;
    g_count++;
}

void    get_east(char *line)
{
    static int  dup = 0;
    if(dup == 1)
        error("error: duplicate east",NULL);
    g_inputs->ea = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
    dup = 1;
    g_count++;
}

void    get_south(char *line)
{
    static int  dup = 0;
    if(dup == 1)
        error("error: duplicate south",NULL);
    g_inputs->so = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
    dup = 1;
    g_count++;
}

void    get_sprite(char *line)
{
    static int  dup = 0;
    if(dup == 1)
        error("error: duplicate sprite",NULL);
    g_inputs->s = ft_substr(line, skip_spaces(line, 3), ft_strlen(line));
    dup = 1;
    g_count++;
}
