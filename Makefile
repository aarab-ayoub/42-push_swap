CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

# External libraries
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = parsing.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build external libraries
$(LIBFT):
	make -C $(LIBFT_DIR)


$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
