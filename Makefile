CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
#MLXFLAG = -L/nfs/homes/sgalli/sgoinfre/progetti/cube3d/minilibx-linux -lmlx -lX11 -lXext -lm
MLXFLAG = -L/home/sgalli/cube3d/minilibx-linux -lmlx -lX11 -lXext -lm
#(path casa)

NAME = cube3D

SRC = 	main.c \
			help/ausiliary.c \
			help/valid_map.c \
			help/alloc_map.c \
			help/start_game.c \
			help/free.c \
       		help/key.c \
			help/error.c \
			    libft/ft_strlcpy.c \
    		    libft/ft_strcmp.c \
			    libft/ft_substr.c \
			    libft/ft_strlen.c \
				libft/ft_strcpy.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c 
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
