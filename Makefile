# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 14:15:08 by ibellash          #+#    #+#              #
#    Updated: 2023/07/13 16:54:04 by ibellash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
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
MLX = mlx/

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS =  -I/opt/X11/include -I/includes -v -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@$(CC) $(CC_FLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) libft/libft.a mlx/libmlx.a

clean:
	@rm -rf $(OBJS)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)

re: fclean all
