
NAME = cub3D

SRCS = raycasting/cub.c\
raycasting/cub_utils.c\
raycasting/draw_utils.c\
raycasting/game_init.c\
raycasting/game_utils.c\
raycasting/linked_list_fc.c\
raycasting/cast_rays.c\
file_parsing/check_args.c\
file_parsing/get_floor_ceiling.c\
file_parsing/get_map.c\
file_parsing/get_paths.c\
file_parsing/get_resolution.c\
file_parsing/map_utils.c\
file_parsing/parsing.c\
file_parsing/parsing_utils.c\
file_parsing/plombier.c\
raycasting/sprite.c\
raycasting/screen.c\
raycasting/draw_floor_ceiling.c\



LIBFT = ./libft/libft.a

INCLUDE = -I ./libft/libft.h -I ./include/cub3d.h -I /usr/local/include

GCC = gcc -Wall -Werror -Wextra
GCCSANITIZE =  gcc -Wall -Werror -Wextra  -g3 -fsanitize=address
MLXMAC =  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 
MLXLINUX = -lmlx -lX11 -lXext -lbsd -lm
all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	$(GCC) $(INCLUDE)  $(SRCS) $(LIBFT) $(MLXMAC) -o $(NAME) 

clean:
	make clean -C libft

linux:
	make linux -C libft
	$(GCC)  $(SRCS) $(LIBFT) $(MLXLINUX) -o $(NAME)

a:
	make -C libft
	$(GCCSANITIZE)  $(SRCS) $(LIBFT) $(MLXMAC) -o $(NAME) 

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(NAME).dSYM
	/bin/rm -rf $(NAME)

re: fclean all






