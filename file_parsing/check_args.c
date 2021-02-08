/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:13:01 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/08 18:11:58 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int g_save;

void	check_args_number(int argc)
{
	if (argc < 2 || argc > 3)
		error("Error: Invalid  number of arguments!", NULL);
}

void	check_extension(char *argv)
{
	if ((ft_strncmp(ft_strrchr(argv, '.'), ".cub", 5)))
		error("Error: Invalid extension!", NULL);
}

void	check_second_arg(int argc, char *argv)
{
	if (argc == 3 && ft_strncmp(&argv[2], "--save", 10))
		error("Error: Invalid second argument!", NULL);
	g_save = 1;
}

void	args_checker(int argc, char **argv)
{
	check_args_number(argc);
	check_extension(argv[1]);
	check_second_arg(argc, argv[2]);
}
