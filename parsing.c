/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/01/16 17:18:17 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int         g_count;
t_cub3d     g_info;

int     line_is_digit(char **line)
{
    int i;
    int j;

    i = 0;
    while(line[i])
    {
        j = 0;
        while(line[i][j])
        {
            if (!ft_isdigit(str[i][j]))
                error("Error: Letters in rosolution!")
            j++;
        }
        i++;
    }
    return(i);
}

void    get_resolution(char *line)
{
    int     i;
    char    **str;
    int     x;
    int     y;

    mlx_get_screen_size(g_mlx.mlx_ptr, &x, &y);
    str = ft_split(line,' ');
    if (str[0][0] == '-' || str[1][0] == '-')
        error("Error: Resolution inputs can not be negative!")
    if (line_is_digit(str) != 2)
        error("Error: Wrong resolution!");
    else
    {
		g_info.width = ft_atoi(str[0]);
		g_info.height = ft_atoi(str[1]);
		g_info.width = g_info.width > x ? x : g_info.width;
		g_info.height = g_info.height > y ? y : g_info.height;
        // Ask about This;
		// g_info.width = g_info.width == -1 ? x : g_info.width;
		// g_info.height = g_info.height == -1 ? y : g_info.height;
		///!!!!!g_count++;
    }  
}

void    get_paths(char *line)
{
    if ()
}





void    line_checker(char *line)
{
    int     i;

    i = 0;

    while (line[i] == ' ')
        i++;
    if (line[i] == 'R' && (line[++i] == ' ' || line[i] == '\t'))
        get_resolution(&line[i]);
    else if (line[i] == 'N' || line[i] == 'S'||line[i] == 'W' || line[i] == 'E')
        get_paths(&line[i]);
    else if ((line[i] == 'F' && line[i + 1] != ' ') || (line[i] == 'C' && line[i + 1] != ' '))
        error("Error: Invalid line in file !");
    else if (line[i] == 'F' && (line[++i] == ' ' || line[i] == '\t'))
        get_flooring(&line[i]);
    else if (line[i] == 'C' && (line[++i] == ' ' || line[i] == '\t'))
        get_ceiling(&line[i]);    
}

// Here I start the parsing;

void    parsing(int argc, char **argv)
{
    int fd;
    char *line;
    int n;

    g_count = 0;z  cjed
    n = 1;
    args_checker(argc, argv);
    
    if(fd = open(argv[1],O_RDONLY))
        error("Error: something went wrong!");
    line = NULL;
    while (n != 0)
    {
        n = get_next_line(fd, &line);
        line_checker(line);
    }      
}