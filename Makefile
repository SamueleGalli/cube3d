CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
MLXFLAG = -lmlx -lX11 -lXext -lm -Lcube/minilibx-linux
NAME = cube3D
SRC = 	cube/start_game/main.c \
		cube/start_game/valid_map.c \
		cube/start_game/start_game.c \
		cube/start_game/alloc_map.c \
   		cube/start_game/key.c \
		cube/start_game/error.c \
		cube/start_game/draw_map.c \
		cube/help/ausiliary.c \
		cube/help/free.c \
		cube/help/ft_strcpy.c \
		cube/help/ft_strlcpy.c \
		cube/help/ft_strcmp.c \
		cube/help/ft_substr.c \
		cube/help/ft_strlen.c \
		cube/get_next_line/get_next_line.c \
		cube/get_next_line/get_next_line_utils.c 
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
