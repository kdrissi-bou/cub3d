
NAME = cub3D

SRCS = srcs/*.c

LIBFT = ./libft/libft.a

INCLUDE = -I ./libft/libft.h -I ./include/cub3d.h -I /usr/local/include

GCC = gcc -Wall -Werror -Wextra  -g3 -fsanitize=address 
MLX =  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 

#all: $(NAME)

all:
	make -C libft
	$(GCC) $(INCLUDE)  $(SRCS) $(LIBFT) $(MLX) -o $(NAME) 

clean:
	

fclean: clean
	

re: fclean all






