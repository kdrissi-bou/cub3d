/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:13:01 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 16:09:23 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int g_save;

void	check_args_number(int argc)
{
	if (argc < 2 || argc > 3)
		error("Error:\n Invalid  number of arguments!", NULL);
}

void	check_extension(char *argv)
{
	if ((ft_strncmp(ft_strrchr(argv, '.'), ".cub", 5)))
		error("Error:\n Invalid extension!", NULL);
}

void	check_second_arg(int argc, char *argv)
{
	if (argc == 3)
	{
		if (!ft_strncmp(argv, "--save", 7))
			g_save = 1;
		else
			error("Error:\n Invalid second argument!", NULL);
	}
}

void	args_checker(int argc, char **argv)
{
	check_args_number(argc);
	check_extension(argv[1]);
	check_second_arg(argc, argv[2]);
}
