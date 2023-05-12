CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
MFLAGS	=	-framework OpenGL -framework Appkit

NAME	= 	cub3D
#NAME_B	=	cub3D_bonus

MLX_DIR	=	./mlx
MLX		=	mlx

INC_DIR	=	-I./inc

INC		=	$(INC_DIR)/cub3d.h
SRC		=	src/main.c \

#INC_B	=	$(INC_DIR)/cub3d_bonus.h \
#SRC_B	=	src/main_bonus.c \


OBJ		=	$(SRC:%.c=%.o)
#OBJ_B	=	$(SRC_B:%.c=%.o)
RM		=	rm -f

all		:	$(NAME)

#bonus	:	$(NAME_B)

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX) $(MFLAGS) -o $@ $(OBJ)

#$(NAME_B)	:	$(OBJ_B)
#	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX) $(MFLAGS) -o $@ $(OBJ_B)

clean	:
	$(RM) $(OBJ)
#$(OBJ_B)

fclean	: clean
	$(RM) $(NAME)
#$(NAME_B)

re : fclean all

.PHONY : all clean fclean re