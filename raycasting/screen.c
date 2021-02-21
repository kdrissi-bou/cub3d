/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:10:46 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 14:25:03 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	write_uint32(int fd, unsigned int bytes)
{
	write(fd, &bytes, 4);
}

static void	write_uint16(int fd, short bytes)
{
	write(fd, &bytes, 2);
}

static void	write_int(int fd, int bytes)
{
	write(fd, &bytes, 4);
}

static void	write_headers(int fd)
{
	unsigned int	size;
	unsigned int	img_size;
	unsigned int	ppm;

	ppm = 96 * 39.375;
	size = WIN_HEIGHT * WIN_WIDTH * 3;
	img_size = size + 54;
	write(fd, "BM", 2);
	write_int(fd, img_size);
	write_uint16(fd, 0);
	write_uint16(fd, 0);
	write_uint32(fd, 54);
	write_uint32(fd, 40);
	write_uint32(fd, (unsigned int)WIN_WIDTH);
	write_uint32(fd, (unsigned int)WIN_HEIGHT);
	write_uint16(fd, 1);
	write_uint16(fd, 24);
	write_uint32(fd, 0);
	write_uint32(fd, img_size);
	write_uint32(fd, ppm);
	write_uint32(fd, ppm);
	write_uint32(fd, 0);
	write_uint32(fd, 0);
}

void		screen(void)
{
	int		fd;
	int		x;
	int		y;
	int		*pixel;
	int		i;

	if (!(fd = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644)))
		exit(-1);
	write_headers(fd);
	loop_key();
	y = WIN_HEIGHT - 1;
	while (y > -1)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = (x + WIN_WIDTH * y) * 4;
			pixel = (int *)(g_img.addr + i);
			write(fd, pixel, 3);
			x++;
		}
		y--;
	}
	close(fd);
	mlx_destroy_image(g_mlx.mlx, g_img.img);
	clean_up();
	exit(0);
}
