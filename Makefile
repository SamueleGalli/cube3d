CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
MLXFLAG = -lmlx -lX11 -lXext -lm -Lcube/minilibx-linux
NAME = cube3D
SRC = 	cube/start_game/main.c \
		cube/start_game/start_game.c \
		cube/map/valid_map.c \
		cube/map/alloc_map.c \
		cube/map/get_next_line.c \
		cube/map/get_next_line_utils.c \
		cube/help/ausiliary.c \
		cube/help/ft_mat_len.c \
		cube/help/ft_strcpy.c \
		cube/help/ft_strlcpy.c \
		cube/help/ft_strcmp.c \
		cube/help/ft_substr.c \
		cube/help/ft_strlen.c \
		cube/ray_casting/rendering.c \
		cube/ray_casting/ray_casting.c \
		cube/ray_casting/orizontal_vertical_ray.c \
   		cube/movements/key.c \
		cube/free_and_error/free.c \
		cube/free_and_error/error.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo Linking... $(NAME)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(MLXFLAG)

%.o : %.c
	@echo Compiling $<...
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
		@echo Cleaning...
		@rm -f $(OBJ)

fclean: clean
		@echo Cleaning...
		@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
