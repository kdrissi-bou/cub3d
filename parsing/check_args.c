/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:13:01 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/07 21:31:35 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int g_save;

// Function to print the error;

void    error(char *err_msg,char **str)
{
    //free_str_array(str);
    ft_lst_clear(&g_file);
    clean_up();
    ft_putstr_fd(err_msg, 2);
    exit(-1);
}
void    clean_up(void)
{
    free(g_inputs->no);
    free(g_inputs->so);
    free(g_inputs->we);
    free(g_inputs->ea);
    free(g_inputs->s);
    free(g_inputs);
   // free_str_array(g_map);
}
// Number of args should be equal to 2 or 3:  exec + .cub + --save;

void     check_args_number(int argc)
{
    if (argc < 2 || argc > 3)
        error("Error: Invalid  number of arguments!",NULL);
}

// check if the file is a .cub;

void    check_extension(char *argv)
{
    if((ft_strncmp(ft_strrchr(argv, '.'),".cub", 6)))
        error("Error: Invalid extension!", NULL);
}

// check if second arg is --save;
void    check_second_arg(int argc, char *argv)
{
    if (argc == 3 && ft_strncmp(&argv[2],"--save", 10))
        error("Error: Invalid second argument!",NULL);
    g_save = 1;
}

//Function that checks the args;

void    args_checker(int argc, char **argv)
{
    check_args_number(argc);
    check_extension(argv[1]);
    check_second_arg(argc, argv[2]);
}
