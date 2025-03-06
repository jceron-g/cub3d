# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 17:06:26 by jceron-g          #+#    #+#              #
#    Updated: 2025/03/06 10:58:30 by jceron-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_B = 
USER = jceron-g & malena-b
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g
LIBFT = include/libft
MLX42 	= include/MLX42/build/libmlx42.a
MLX_FLAGS = -Iinclude -ldl -lglfw -g -pthread -lm 
SRC_DIR = src/
OBJ_DIR = obj/
SRC_DIR_BONUS =

DEF_COLOR = \033[0;39m
MAGENTA   = \033[35;1m
YELLOW    = \033[33;1m
GREEN     = \033[32;1m
WHITE     = \033[37;1m
RESET     = \033[0m
GRAY 	  = \033[0;90m
BLUE      = \033[34;1m
CYAN      = \033[37;1m
RED		  = \033[31;1m

SRC_FILES = main parse utils map auxiliar_functions free
SRC_FILES_BONUS = 

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	$(OBJ) $(MLX42)
			@make all -C $(LIBFT)
			@echo "$(GREEN)Welcome to $(USER) Cub3D!$(RESET)"
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) $(MLX42) $(MLX_FLAGS) -lft  -o $(NAME)
			@echo "$(GREEN)Compilation successful!$(RESET)"

$(MLX42):
		@cmake -B include/MLX42/build -S include/MLX42
		@cmake --build include/MLX42/build -j4

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(BLUE)Compiling, please wait.: $(RESET) $(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			
bonus:		$(OBJ_BONUS)
			@make all -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT) -lft -o $(NAME_B)
			@echo "$(MAGENTA)Bonus compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR_BONUS)%.c | $(OBJF)
			@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -frf $(OBJ_DIR)
			@make clean -s -C include/libft/
			@make clean -s -C include/MLX42/build/
			@make all clean -C $(LIBFT)
			@echo "$(RED)Cleaning libraries, please wait.$(RESET)"
			@echo "$(RED)Cleaning program executables, please wait.$(RESET)"

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@make clean -s -C include/libft/
			@make clean -s -C include/MLX42/build/
			@rm -rf $(NAME_B)
			@rm -rf $(OBJ_BONUS)
			@make fclean -C $(LIBFT)
			@echo "$(YELLOW)Cleaning libraries.$(RESET)"
			@echo "$(YELLOW)Cleaning program objects.$(RESET)"

re: fclean all
			@echo "$(MAGENTA)Program recompiled$(RESET)"

norm:
			@norminette $(SRC) $(LIBFT) $(SRC_BONUS)
						
.PHONY: all bonus clean fclean re norm