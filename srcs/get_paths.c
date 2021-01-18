#include "../include/cub3d.h"


   

void    store_path(char *line, int cor)
{
    

}


void    get_paths(char *line)
{
    if (!ft_strncmp(line,"NO ",3) || !ft_strncmp(line, "NO\t", 3))
        store_path(line, 1);
    else if (!ft_strncmp(line,"SO ",3) || !ft_strncmp(line, "SO\t", 3))
        store_path(line,2);
    else if (!ft_strncmp(line,"WE ",3) || !ft_strncmp(line, "WE\t", 3))
        store_path(line,3);
    else if (!ft_strncmp(line,"EA ",3) || !ft_strncmp(line, "EA\t", 3))
        store_path(line,4);
    else 
        error("ERROR!");
}