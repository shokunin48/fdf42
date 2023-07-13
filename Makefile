# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 14:15:08 by ibellash          #+#    #+#              #
#    Updated: 2023/07/13 15:25:28 by ibellash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
		drawing.c \
		initialization.c \
		iso.c \
		read_file.c \
		moving.c \
		rotations.c \
		utils.c \
		utils2.c 

NAME = fdf

LIBFT = libft/
MLX = mlx_mac/

SRCS_DIR = srcs/

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS =  -I/opt/X11/include -I/includes -v -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -Imlx_mac -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(MLX)
	mv $(MLX)/libmlx.dylib libmlx.dylib
	@gcc -o3 $(CC_FLAGS) -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) libft/libft.a ./libmlx.dylib

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f libmlx.dylib

re: fclean all
