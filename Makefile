# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 13:05:02 by tponnusa          #+#    #+#              #
#    Updated: 2023/06/23 18:39:35 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

CC 			= cc

CFLAGS 		= -Wall -Wextra -Werror

MLX_DIR		= mlx

MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR 	= libft

LIBFT_LIB 	= $(LIBFT_DIR)/libft.a

MLX_LIB		= $(MLX_DIR)/libmlx.a

SRC 		= 	so_long.c so_long_utils.c so_long_utils2.c parsing_map.c map_game.c handle_key_event.c \
			  	find_valid_path.c ft_initialize.c ft_free_memory.c ft_trim.c ft_exit.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ         =  $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
			make -C $(MLX_DIR) all
			make -C $(LIBFT_DIR) all
			$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS)  $(LIBFT_LIB) -o $(NAME)

all 	:	$(NAME)

clean	: 
			make -C $(MLX_DIR) clean
			make -C $(LIBFT_DIR) clean
			rm -f $(OBJ)

fclean	: 	clean
			make -C $(LIBFT_DIR) fclean
			rm -f $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean bonus re