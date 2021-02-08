/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plombier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:08:32 by drissi            #+#    #+#             */
/*   Updated: 2021/02/08 18:59:25 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error(char *err_msg, char **str)
{
	free_str_array(str);
	ft_lst_clear(&g_file);
	clean_up();
	ft_putstr_fd(err_msg, 2);
	exit(-1);
}

void	clean_up(void)
{
	free(g_inputs->no);
	free(g_inputs->so);
	free(g_inputs->we);
	free(g_inputs->ea);
	free(g_inputs->s);
	free(g_inputs);
	free_str_array(g_map);
}
