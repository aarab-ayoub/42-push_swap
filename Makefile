CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

# External libraries
# LIBFT_DIR = libft
# PRINTF_DIR = ft_printf
# GNL_DIR = gnl

# LIBFT = $(LIBFT_DIR)/libft.a
# PRINTF = $(PRINTF_DIR)/libftprintf.a
# GNL = $(GNL_DIR)/get_next_line.a

SRC = parsing.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "push_swap compiled"

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Build external libraries
# $(LIBFT):
# 	@make -C $(LIBFT_DIR)

# $(PRINTF):
# 	@make -C $(PRINTF_DIR)

# $(GNL):
# 	make -C $(GNL_DIR)

clean:
	@rm -f $(OBJ)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "push_swap removed"

re: fclean all

.PHONY: all clean fclean re