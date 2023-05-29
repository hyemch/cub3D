# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 17:14:23 by yongmipa          #+#    #+#              #
#    Updated: 2023/05/24 17:14:011 by suhwpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f

SRCS_DIR	= ./mandatory/srcs/
SRCSB_DIR	= ./bonus/srcs/
LIB_DIR		= ./libft/
MLX_DIR		= ./mlx/

MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	get_next_line.c \
				queue_utils.c queue_utils2.c \
				utils.c \
				map_validate_1.c \
				main.c\
				map_validate_2.c \
				map_validate_3.c \
				use_bfs.c \
				initialize.c \
				map_valid_utils.c \
				map_valid_utils_1.c \
				map_validate_1.1.c \
				map_context_check.c \
				map_wall_check.c \
				key_handle.c \
				key_handle2.c \
				key_handle_utils.c \
				set_ray_values.c \
				set_ray_values2.c \
				main_loop.c \
				main_loop_utils.c \
				ray_casting.c \

SRC_B		=	get_next_line_bonus.c \
				queue_utils_bonus.c queue_utils2_bonus.c \
				utils_bonus.c \
				map_validate_1_bonus.c \
				main_bonus.c\
				map_validate_2_bonus.c \
				map_validate_3_bonus.c \
				use_bfs_bonus.c \
				initialize_bonus.c \
				map_valid_utils_bonus.c \
				map_valid_utils_1_bonus.c \
				map_validate_1.1_bonus.c \
				map_context_check_bonus.c \
				map_wall_check_bonus.c \
				key_handle_bonus.c \
				key_handle2_bonus.c \
				key_handle_utils_bonus.c \
				set_ray_values_bonus.c \
				set_ray_values2_bonus.c \
				main_loop_bonus.c \
				main_loop_utils_bonus.c \
				ray_casting_bonus.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
SRCSB		=	$(addprefix $(SRCSB_DIR), $(SRC_B))
OBJS		=	$(SRCS:.c=.o)
OBJSB		=	$(SRCSB:.c=.o)

ifdef CUB3D_WITH_BONUS
	INC_DIR = ./bonus/includes/
    OBJ_FILES = $(OBJSB)
else
	INC_DIR = ./mandatory/includes/
    OBJ_FILES = $(OBJS)
endif

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_DIR)

all : $(NAME)

bonus :
	make CUB3D_WITH_BONUS=1 all

$(NAME) : $(OBJ_FILES)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(FLAGS) $^ -Llibft -lft $(MLX_FLAGS) -o $@

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJSB)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus_re :
	make fclean
	make bonus

.PHONY	: all bonus clean fclean re