
NAME = cub3D

SRCS = srcs/*.c

LIBFT = ./libft/libft.a

INCLUDE = -I ./libft/libft.h -I ./include/cub3d.h -I /usr/local/include

GCC = gcc -Wall -Werror -Wextra  -g3 -fsanitize=address 
MLX =  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 

#all: $(NAME)

all:
	echo ranni hnna
	make -C libft
	echo ranni hnna
	$(GCC) $(INCLUDE)  $(SRCS) $(LIBFT) $(MLX) -o $(NAME) 
	echo ranni hnna

clean:
	

fclean: clean
	

re: fclean all






