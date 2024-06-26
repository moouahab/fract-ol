# Define colors
GREEN = \033[4;32m
YELLOW = \033[1;33m
NC = \033[0m  # No Color

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = libft
MLX_DIR = mlx
PRINTF_DIR = printf
OBJ_DIR = obj
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    INCLUDES = -I/usr/include -I$(MLX_DIR)
    MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
else
    INCLUDES = -I/opt/X11/include -I$(MLX_DIR)
    MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRCS = src/main.c src/utils.c maths/complexe_alb.c maths/utils_complexe.c\
		src/color.c src/hook.c fractal/mandelbrot.c src/parsing.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = fract-ol

all: create_obj_dir libft mlx printf $(MLX_LIB) $(PRINTF_LIB) $(NAME)
	@echo "$(GREEN)Compilation successful!$(NC)"

create_obj_dir:
	@mkdir -p $(OBJ_DIR)

libft:
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@make -C $(LIBFT_DIR)

mlx:
	@echo "$(YELLOW)Compiling mlx...$(NC)"
	@make -C $(MLX_DIR)

printf:
	@echo "$(YELLOW)Compiling printf...$(NC)"
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(PRINTF_LIB) $(LIBFT)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(MLX_LIB):
	@make -s -C $(MLX_DIR)

$(PRINTF_LIB):
	@make -s -C $(PRINTF_DIR)

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@make -s -C $(PRINTF_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean:
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(PRINTF_DIR) fclean
	@rm -f $(NAME) $(MLX_LIB) $(PRINTF_LIB)
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all create_obj_dir libft mlx printf clean fclean re
