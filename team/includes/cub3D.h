/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:17:25 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/15 16:53:37 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "so_long.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct s_map // 맵에 대한 정보 담긴 구조체
{
	char	**map;
	int		**f;
	int		**c;
}	t_map;

typedef struct s_img //이미지, 해상도 담긴 구조체
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		*info_flag[6];
	int		w;
	int		a;
	int		s;
	int		d;
	t_img	*img;
	t_map	*map;
}	t_game;

/* utils.c */
void	ft_free(char **str);
int		ft_size(char **str);
int		ft_isspace(char c);
void	ft_err(char *str);

#endif