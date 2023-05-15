/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:58:08 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/15 17:40:41 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "queue.h"
# include <stddef.h>

# define KEY_PRESS			2
# define DESTROY_NOTIFY		17

# define INVALID_KEYCODE	0

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define TRUE	1
# define FALSE	0

# define IMG_ARRAY_SIZE	81

typedef struct s_map
{
	// size_t	width;
	// size_t	height;
	// char	*str;
	// size_t	p_pos;
	// size_t	coll_sum;
}	t_map;

typedef struct s_img
{
	// void	*wall;
	// void	*land;
	// void	*exit;
	// void	*pac;
	// void	*coll;
}	t_img;

typedef struct s_game
{
	// void	*mlx;
	// void	*win;
	// t_map	*map;
	// t_img	*img;
	// size_t	move_cnt;
	// size_t	coll_cnt;
}	t_game;

#endif
