#include "../include/cub3d.h"

int     path_start(char *line, int i)
{
    	while (line[i])
	{
		if (line[i] == '.' || line[i] != ' ')
			return (i);
		i++;
	}
	return (i);

}
   


void    get_paths(char *line)
{
    if (!ft_strncmp(line,"NO ",3) || !ft_strncmp(line, "NO\t", 3))
        g_inputs.no = ft_substr(line, path_start(line, 3), ft_strlen(line));
    else if (!ft_strncmp(line,"SO ",3) || !ft_strncmp(line, "SO\t", 3))
        g_inputs.so = ft_substr(line, path_start(line, 3), ft_strlen(line));
    else if (!ft_strncmp(line,"WE ",3) || !ft_strncmp(line, "WE\t", 3))
        g_inputs.we = ft_substr(line, path_start(line, 3), ft_strlen(line));
    else if (!ft_strncmp(line,"EA ",3) || !ft_strncmp(line, "EA\t", 3))
        g_inputs.ea = ft_substr(line, path_start(line, 3), ft_strlen(line));
    else if(!ft_strncmp(line,"S ",2) || !ft_strncmp(line, "S \t", 3))
        g_inputs.s = ft_substr(line, path_start(line, 3), ft_strlen(line));
    else 
        error("ERROR! get_paths");
    g_count +=10;
}