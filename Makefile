CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
NAME = cube3D

SRC = 	       main.c \
	 	 help/error.c \
	libft/ft_strcmp.c \
	libft/ft_substr.c \
	libft/ft_strlen.c \
   libft/ft_strlcpy.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo Linking... $(NAME)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

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