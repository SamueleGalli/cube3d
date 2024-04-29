CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
MLXFLAG = -lmlx -lX11 -lXext -lm -Lcube/minilibx-linux
NAME = cube3D
SRC = 	cube/start_game/main.c \
		cube/start_game/start_game.c \
		cube/map/flood_fill.c \
		cube/map/flood_fill2.c \
		cube/map/alloc_map.c \
		cube/map/get_next_line.c \
		cube/map/get_next_line_utils.c \
		cube/map/coordinate_floor_ceiling.c \
		cube/map/find_texture_image.c \
		cube/map/error_map.c \
		cube/help/ausiliary.c \
		cube/help/ft_mat_len.c \
		cube/help/ft_strcpy.c \
		cube/help/ft_strlcpy.c \
		cube/help/ft_atoi.c \
		cube/help/ft_strcmp.c \
		cube/help/ft_substr.c \
		cube/help/ft_strlen.c \
		cube/ray_casting/rendering.c \
		cube/ray_casting/texturing.c \
		cube/ray_casting/raycasting.c \
		cube/ray_casting/painting.c \
		cube/ray_casting/floor_and_ceiling.c \
   		cube/movements/key.c \
		cube/movements/key_pressed.c \
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
