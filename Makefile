
NAME = cub3D

SRCS = srcs/cub.c srcs/draw_utils.c srcs/linked_list_fc.c 
 parsing/args-checker.c parsing/get_map.c  parsing/get_paths.c parsing/parsing.c\
 parsing/check_args.c parsing/get_floor_ceiling.c parsing/get_map.c\
parsing/get_paths.c parsing/get_resolution.c parsing/map_utils.c parsing/parsing.c\
parsing/parsing_utils.c 

LIBFT = ./libft/libft.a

INCLUDE = -I ./libft/libft.h -I ./include/cub3d.h -I /usr/local/include

GCC = gcc -Wall -Werror -Wextra  #-g3 -fsanitize=address 
MLXMAC =  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 
MLXLINUX = -lmlx -lX11 -lXext -lbsd -lm
#all: $(NAME)

all:
	make -C libft
	$(GCC) $(INCLUDE)  $(SRCS) $(LIBFT) $(MLXMAC) -o $(NAME) 

clean:
	
linux:
	make linux -C libft
	$(GCC)  $(SRCS) $(LIBFT) $(MLXLINUX) -o $(NAME) 

fclean: clean
	

	re: fclean all






