
NAME = cub3D

SRCS = srcs/*.c

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






