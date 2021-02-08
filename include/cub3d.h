/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:53:13 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/08 22:25:20 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WIN_HEIGHT g_inputs->height
# define WIN_WIDTH g_inputs->width
# define UP_ARROW 126
# define DW_ARROW 125
# define LF_ARROW 123
# define RT_ARROW 124
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC 53
# define MAP_ROWS g_rows
# define MAP_COLUMNS g_columns
# define MOVEMENT_SPEED 5
# define ROTATION_SPEED 0.06


 

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
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_mlx;

typedef struct	s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	angle;
}				t_player;

typedef struct	s_key
{
	int		up;
	int		down;
	int		right;
	int		left;
}				t_key;

t_mlx		g_mlx;
t_player	g_player;
t_key		g_key;
int         g_count;
t_cub3d     *g_inputs;
t_list		*g_file;
int			g_columns;
int			g_rows;
char		**g_map;
int			g_save;
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
void	print_map(void);
int		key_released(int key);
int		key_pressed(int key);
void	init(void);
void	player_init(void);
void	mlx_struct_init(void);
float	normalize_angle(float angle);


#endif