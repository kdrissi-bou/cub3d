/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:07:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 17:21:02 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parsing(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		n;

	n = 1;
	args_checker(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Error:\n something went wrong! could not open file!", NULL);
	line = NULL;
	while (n != 0)
	{
		n = get_next_line(fd, &line);
		ft_lstadd_back(&g_file, ft_lstnew(line));
		line_checker(line);
	}
	if (g_count != 8)
		error("Error:\nWRONG NUMBER OF INPUTS", NULL);
	map_treatment();
	ft_lst_clear(&g_file);
	if (close(fd) == -1)
		error("Error:\n something went wrong! could not close file!", NULL);
}

void	line_checker(char *line)
{
	if (!ft_strncmp(line, "R ", 2))
		get_resolution(line);
	else if (!ft_strncmp(line, "NO ", 3))
		get_north(line);
	else if (!ft_strncmp(line, "SO ", 3))
		get_south(line);
	else if (!ft_strncmp(line, "WE ", 3))
		get_west(line);
	else if (!ft_strncmp(line, "EA ", 3))
		get_east(line);
	else if (!ft_strncmp(line, "S ", 2))
		get_sprite(line);
	else if (!ft_strncmp(line, "F ", 2))
		get_flooring(line);
	else if (!ft_strncmp(line, "C ", 2))
		get_ceiling(line);
	else if (line_is_empty(line) || map_first_digit(line))
		return ;
	else
		error("Error:\n Invalid identifier!", NULL);
}
