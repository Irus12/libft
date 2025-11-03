SRC := $(wildcard *c)
NAME := libft.a
OBJ := $(SRC:.c=.o)
RM := rm -f
CC := gcc -Wextra -Werror -Wall 

all: $(NAME)

$(NAME): $(OBJ) #crée archive
	ar rcs $@ $^
%.o: %.c #converti .c en .o
	$(CC) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all


.PHONY: all clean fclean re