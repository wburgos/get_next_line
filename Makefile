NAME = a.out
SRC = get_next_line.c main.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -g3

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -Llibft -lft

%.o: %.c get_next_line.h
	$(CC) $(FLAGS) -c $< -I. -Ilibft/includes

.PHONY: clean
clean:
	/bin/rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
