/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:53:13 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/13 12:14:11 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"
# include "keys.h"

# define WIN_HEIGHT g_inputs->height
# define WIN_WIDTH g_inputs->width
# define MAP_ROWS g_rows
# define MAP_COLUMNS g_columns
# define WALK_SPEED 5
# define TURN_SPEED 0.03
# define FOV_ANGLE (60 * (M_PI / 180))
# define TRUE 1
# define FALSE 0
# define TILE_SIZE (g_inputs->width / g_columns)
# define RAD(x) (x * M_PI / 180)
 

typedef struct 		s_rgb
{
	int				red;
	int				green;
	int				blue; 
}					t_rgb;


typedef	struct s_cub3d
{
	int				height;
	int 			width;
	char 			*no;
	char			*so;
	char 			*we;
	char 			*ea;
	char 			*s;
	t_rgb 			c;
	t_rgb 			f;
}				t_cub3d;

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_player
{
	float	x;
	float	y;
	// float	dx;
	// float	dy;
	float	angle;
}				t_player;




typedef struct  s_img {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

typedef struct s_ray {
	int 	up;
	int		down;
	int 	left;
	int 	right;
	float	x_inter;
	float	y_inter;
	float	xstep;
	float	ystep;
	int		horz_hit;
	float	x_hit_horz;
	float	y_hit_horz;
	float	next_horz_X;
	float	next_horz_Y;
	int		vert_hit;
	float	x_hit_vert;
	float	y_hit_vert;
	float	next_vert_X;
	float	next_vert_Y;
	float	check_X;
	float	check_Y;
	float	horz_distance;
	float	vert_distance;
	int 	content;
}			t_ray;

typedef struct	s_rays{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			up;
	int			down;
	int			left;
	int			right;
	int			was_hit_vert;
}				t_rays;
	
t_mlx		g_mlx;
t_player	g_player;
t_img		g_img;
int         g_count;
t_cub3d     *g_inputs;
t_list		*g_file;
int			g_columns;
int			g_rows;
char		**g_map;
int			g_save;
int		g_walk_direction;
int		g_turn_direction;
t_ray	g_ray;
t_rays	*g_rays;
int		g_sprite_count;
// FUNCTION PROTOTYPES

void	draw_square(int width, int height, int x, int y);
int		buttons(int key, void *param);
void	draw_map(void);
void	drawRay(int rx, int ry);
void	draw_player(int x0, int y0, int radius);
void	draw_line(int X0, int Y0, int X1, int Y1, int color);
void    store_path(char *line, int cor);
void	get_flooring(char *);;
void	parsing(int argc, char **argv);
void    check_args_number(int argc);
void    error(char *err_msg, char **str);
void    check_extension(char *argv);
void    line_checker(char *line);
void	args_checker(int argc, char **argv);
void	get_ceiling(char *line); 
void	get_paths(char *line);
void    map_treatment(void);
int     map_starts_here(char *line);
void    map_debut(void);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lst_clear(t_list **lst);
void    clean_up(void);
void    free_str_array(char **str);
int		map_first_digit(char *line);
void    spacer(void);
int     skip_spaces(char *line, int i);
int     line_is_digit(char **line);
void    get_resolution(char *line);
void    get_sprite(char *line);
void    get_south(char *line);
void    get_east(char *line);
void    get_west(char *line);
void    get_north(char *line);
void	store_rgb(char **str, char type);
void	get_ceiling(char *line);
void	get_flooring(char *line);
void	check_comma(char *line);
int		line_is_empty(char *line);
float	normalize_angle(float angle);
void	print_map(void);
int		key_released(int key);
int		key_pressed(int key);
void	init(void);
void	player_init(void);
void	mlx_struct_init(void);
float	normalize_angle(float angle);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_rays(void);
void	set_angle(char player_pos);
void	init_player(void);
void	cast_vert(float ray_angle);
void	init_vert(float ray_angle);
int		distance(float x1, float y1, float x2, float y2);
void	init_horz(float ray_angle);
void	cast_horz(float	ray_angle);
void	store_rays(int strip_id, float ray_angle);
int		has_wall_at(float x, float y);




#endif