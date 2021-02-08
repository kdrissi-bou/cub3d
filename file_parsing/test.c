/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 21:38:47 by drissi            #+#    #+#             */
/*   Updated: 2021/02/08 18:29:06 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/cub3d.h"

void	print_map(void)
{
	int i = 0;
	while (g_map[i])
	{
		printf("%s\n",g_map[i]);
		i++;
	}
}
void	init(void)
{
	g_count	= 0;
	g_inputs = (t_cub3d *)malloc(sizeof(t_cub3d));
	g_inputs->we =NULL;
	g_inputs->ea =NULL;
	g_inputs->so =NULL;
	g_inputs->no =NULL;
	g_inputs->s =NULL;
	g_columns = 0;
	g_rows = 2;
	g_map = NULL;
}

int main(int argc, char **argv)
{
    init();
    parsing(argc, argv);
    printf("%d\n",g_inputs->height);
    printf("%d\n",g_inputs->width);
    printf("%s\n",g_inputs->no);
    printf("%s\n",g_inputs->so);
    printf("%s\n",g_inputs->we);
    printf("%s\n",g_inputs->ea);
    printf("%s\n",g_inputs->s);
    printf("%d\n",g_inputs->c.red);
    printf("%d\n",g_inputs->c.green);
    printf("%d\n",g_inputs->c.blue);
    printf("%d\n",g_inputs->f.red);
    printf("%d\n",g_inputs->f.green);
    printf("%d\n",g_inputs->f.blue);
    //free_str_array(g_map);
    clean_up();
    // print_map();
    
}