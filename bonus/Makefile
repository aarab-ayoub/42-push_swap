CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC = parsing.c	utils/ft_atoi.c	utils/ft_isdigit.c	utils/ft_lstadd_back.c utils/ft_putnbr_fd.c \
      utils/ft_lstadd_front.c	utils/ft_lstclear.c	utils/ft_lstlast.c	utils/ft_lstnew.c	utils/ft_lstsize.c	utils/ft_putchar_fd.c \
      utils/ft_putendl_fd.c	utils/ft_putstr_fd.c	utils/ft_split.c	utils/ft_strcmp.c	utils/ft_strlen.c \
      utils/is_delimiter.c utils/ft_strchr.c utils2.c parsing2.c moves/move.c moves/move2.c moves/move3.c \
	  hardcode.c rules.c utils.c hardcode2.c big_sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "push_swap compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "push_swap removed"

re: fclean all

.PHONY: all clean fclean re