/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:37:12 by drissi            #+#    #+#             */
/*   Updated: 2021/02/21 16:16:09 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_comma(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		if (j > 2)
			error("Error:\n error in rgb!\n", NULL);
		i++;
	}
}

int		line_is_empty(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int		skip_spaces(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ')
			return (i);
		i++;
	}
	return (i);
}

int		line_is_digit(char **line)
{
	int i;
	int j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (!ft_isdigit(line[i][j]))
				error("Error:\n not a digit", line);
			j++;
		}
		i++;
	}
	return (i);
}

void	free_str_array(char **str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}
