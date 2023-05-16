# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 17:14:23 by yongmipa          #+#    #+#              #
#    Updated: 2023/05/16 17:31:40 by suhwpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
FLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./src/
LIB_DIR		= ./libft/
# MLX_DIR		= ./mlx/

LIB_NAME	= ./libft/libft.a
INCS		= -I includes
#MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	get_next_line.c \
				queue_utils.c queue_utils2.c \
				utils.c \
				map_validate_1.c \
				main.c\
				map_validate_2.c \
				use_bfs.c \

LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
# make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft -I $(INCS_DIR)
# -L
# $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	make -C $(LIB_DIR) clean
# make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : fclean all

PHONY	: all clean fclean re