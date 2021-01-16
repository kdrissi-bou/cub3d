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

int g_count;

int     lineIsDigit(char **line)
{
    int i;
    int j;
    i = 0;
    
    while(line[i] )
    {
        j = 0;
        while(line[i][j])
        {
            if (!ft_isdigit(str[i][j]))
                error("Error: Invalid resolution!")
            j++;
        }
        i++;
    }
}

void    resolution(char *line)
{
    char **str;
    str = ft_split(line,' ');
    if (str[0][0] == '-' || str[1][0] == '-')
        error("Error: Wrong resolution inputs!")
    if (lineIsDigit())
    {
        /* code */
    }
    
}







void    line_checker(char *line)
{
    int     i;

    i = 0;

    while (line[i] == ' ')
        i++;
    if (line[i] == 'R' && (line[++i] == ' ' || line[i] == '\t'))
        resolution(&line[i]);
    else if (line[i] == 'N' || line[i] == 'S'||line[i] == 'W' || line[i] == 'E')
        paths(&line[i]);
    else if ((line[i] == 'F' && line[i + 1] != ' ') || (line[i] == 'C' && line[i + 1] != ' '))
        error("Error: Invalid line in file !");
    else if (line[i] == 'F' && (line[++i] == ' ' || line[i] == '\t'))
        flooring(&line[i]);
    else if (line[i] == 'C' && (line[++i] == ' ' || line[i] == '\t'))
        ceiling(&line[i]);
     
}

// Here I start the parsing;

void    parsing(int argc, char **argv)
{
    int fd;
    char *line;
    int n;

    g_count = 0;
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