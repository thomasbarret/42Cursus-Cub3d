# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 01:52:16 by tbarret           #+#    #+#              #
#    Updated: 2024/06/27 12:29:48 by tbarret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3d
BONUS_NAME	=	cub3d_bonus
CC 			=	cc
CFLAGS 		=	-Wall -Wextra -Werror
SRCS_PATH	= 	./src
				
SRCS_GNL	= 	$(SRCS_PATH)/functions/gnl/get_next_line.c \
				$(SRCS_PATH)/functions/gnl/get_next_line_utils.c 	

SRCS_LIBFT	= 	$(SRCS_PATH)/functions/libft/ft_bzero.c \
				$(SRCS_PATH)/functions/libft/ft_calloc.c \
				$(SRCS_PATH)/functions/libft/ft_split.c \
				$(SRCS_PATH)/functions/libft/ft_strstr.c \
				$(SRCS_PATH)/functions/libft/ft_substr.c \
				$(SRCS_PATH)/functions/libft/ft_strncmp.c \
				$(SRCS_PATH)/functions/libft/ft_strcmp.c \
				$(SRCS_PATH)/functions/libft/ft_atoi.c \
				$(SRCS_PATH)/functions/libft/ft_bzero.c
SRCS_FILE 	= 	$(SRCS_GNL) \
				$(SRCS_LIBFT) \
				$(SRCS_PATH)/functions/cub3d.c \
				$(SRCS_PATH)/functions/file.c \
				$(SRCS_PATH)/functions/utils.c \
				$(SRCS_PATH)/functions/utils_file.c \
				$(SRCS_PATH)/functions/map.c \
				$(SRCS_PATH)/functions/player.c \
				$(SRCS_PATH)/functions/image.c \
				$(SRCS_PATH)/functions/raycasting/ray.c \
				$(SRCS_PATH)/functions/raycasting/drawing.c \
				$(SRCS_PATH)/functions/raycasting/math.c \
				$(SRCS_PATH)/functions/raycasting/mouvement.c

OBJS_FILE	=	$(SRCS_FILE:.c=.o)

BONUS_SRCS_PATH	= 	./src_bonus
				
BONUS_SRCS_GNL		= 	$(BONUS_SRCS_PATH)/functions/gnl/get_next_line.c \
						$(BONUS_SRCS_PATH)/functions/gnl/get_next_line_utils.c 	

BONUS_SRCS_LIBFT	= 	$(BONUS_SRCS_PATH)/functions/libft/ft_bzero.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_calloc.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_split.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_strstr.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_substr.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_strncmp.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_strcmp.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_atoi.c \
						$(BONUS_SRCS_PATH)/functions/libft/ft_bzero.c
BONUS_SRCS_FILE 	=   $(BONUS_SRCS_GNL) \
						$(BONUS_SRCS_LIBFT) \
						$(BONUS_SRCS_PATH)/functions/cub3d.c \
						$(BONUS_SRCS_PATH)/functions/file.c \
						$(BONUS_SRCS_PATH)/functions/utils.c \
						$(SRCS_PATH)/functions/utils_file.c \
						$(BONUS_SRCS_PATH)/functions/map.c \
						$(BONUS_SRCS_PATH)/functions/player.c \
						$(BONUS_SRCS_PATH)/functions/image.c \
						$(BONUS_SRCS_PATH)/functions/raycasting/ray.c \
						$(BONUS_SRCS_PATH)/functions/raycasting/drawing.c \
						$(BONUS_SRCS_PATH)/functions/raycasting/math.c \
						$(BONUS_SRCS_PATH)/functions/raycasting/mouvement.c
BONUS_OBJS_FILE		=	$(BONUS_SRCS_FILE:.c=.o)

all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g3

$(NAME) : $(OBJS_FILE)
	@make -C ./libs/mlx
	$(CC) -g3 $^ -o $@ -L./libs/mlx -lmlx -lXext -lX11 -lz -lm ./libs/mlx/libmlx.a

bonus : $(BONUS_OBJS_FILE)
	@make -C ./libs/mlx
	$(CC) -g3 $^ -o $(BONUS_NAME) -L./libs/mlx -lmlx -lXext -lX11 -lz -lm ./libs/mlx/libmlx.a

clean:
	@make clean -C ./libs/mlx
	rm -f $(OBJS_FILE)
	rm -f $(BONUS_OBJS_FILE)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all
