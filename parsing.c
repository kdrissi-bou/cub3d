/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2020/12/24 16:40:30 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int g_count;

void    error(char *str)
{
    ft_putstr_fd(str, 1);
    exit(-1);
}
void    check_name(char *argv)
{
    if((ft_strncmp(ft_strrchr(argv, '.'),".cub", 6))
        error("Error: Invalid file name!");
}

int     lineIsDigit(char **line)
{
    int i;
    int j;
    i = 0;
    
    while(line[i] )
    {
        j = 0;
        while(str[i][j])
        {
            if (!ft_isdigit(str[i][j]))
                error(Error: Invalid resolution!)
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







void    check_line(char *line)
{
    int     i;

    i = 0;

    while (line[i] == ' ')
        i++;
    if (line[i] == 'R' && (line[++i] == ' ' || line[++i] == '\t'))
        resolution(line);
    else if (line[i] == 'N' || line[i] == 'S'||line[i] == 'W' || line[i] == 'E')
        paths();
    else if (())
    
    
}








void    parsing(int argc, char **argv)
{
    int fd;
    char *line;
    int n;

    g_count = 0;
    n = 1;
    if (argc < 2 || argc > 3)
        error("Error: Invalid number of args!");
    check_name(argv[1]);
    if (argc == 3 && ft_strncmp(argv[2],"--save", 10))
        error("Error: Invalid argument!");
    fd = open(argv,O_RDONLY);
    line = NULL;
    while (n != 0)
    {
        n = get_next_line(fd, &line);
        check_line(line);
    }      
}
