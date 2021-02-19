/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:10:46 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/18 13:03:24 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"





static void	init_data(t_bitmap *bmp)
{
	bmp->pd_offset = 54;
	bmp->header_size = 40;
	bmp->image_width = WIN_WIDTH;
	bmp->image_height = WIN_HEIGHT;
	bmp->bpp = 24;
	bmp->width_in_bytes = ((bmp->image_width * bmp->bpp + 31) / 23) * 4;
	bmp->planes = 1;
	bmp->image_size = bmp->width_in_bytes * bmp->image_height;
	bmp->file_size = 54 + bmp->image_size;
}




static void	set_bmp_header(unsigned char *buffer, t_bitmap *bmp)
{
	ft_memcpy(buffer, "BM", 2);
	ft_memcpy(buffer + 2, &(bmp->file_size), 4);
	ft_memcpy(buffer + 10, &(bmp->pd_offset), 4);
	ft_memcpy(buffer + 14, &(bmp->header_size), 4);
	ft_memcpy(buffer + 18, &(bmp->image_width), 4);
	ft_memcpy(buffer + 22, &(bmp->image_height), 4);
	ft_memcpy(buffer + 26, &(bmp->planes), 2);
	ft_memcpy(buffer + 28, &(bmp->bpp), 2);
	ft_memcpy(buffer + 34, &(bmp->image_size), 4);
}


static void	fill_buffer(int fd)
{    int x;
    int y;
	int x2;
    

	y = WIN_HEIGHT;
	while (--y >= 0)
	{
		x = WIN_WIDTH;
		x2 = 0;
		while (--x >= 0)
		{
		//	printf("%c\n",g_img.addr[y * WIN_WIDTH + x2] );
			write(fd, 0, 3);
			x2++;
		}
	}
}

void		screen(void)
{
	int				fd;
	t_bitmap		bmp;
	unsigned char	header[54];
   // loop_key();
	init_data(&bmp);
	fd = open("img.bmp", O_RDWR | O_CREAT, 500);
	set_bmp_header(header, &bmp);
	write(fd, header, 54);
	fill_buffer(fd);
	close(fd);

}