/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:17:25 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/22 15:30:55 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 10000

# define KEY_PRESS			2
# define DESTROY_NOTIFY		17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define INVALID_KEYCODE	0

# define TRUE 1
# define FALSE 0

# include "queue.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# define WIDTH 640
# define HEIGHT 640
# define MAPWIDTH 40
# define MAPHEIGHT 20
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct	s_timg
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_timg;
typedef struct	s_dinfo
{
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	time;
	double	oldtime;
	int		buf[MAPWIDTH][MAPHEIGHT];
	int		**texture;
	t_timg	*timg;

}	t_dinfo;

typedef struct s_info // 맵에 대한 정보 담긴 구조체
{
	char	**map;
	int		info_flag[6];
	int		w;
	int		e;
	int		s;
	int		n;
	int		p_pos[2]; //0:y 1:x
	int		player;
	int		f[3];
	int		c[3];
}	t_info;

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
	t_img	*img;
	t_info	*info;
	t_dinfo	*dinfo;
}	t_game;

/* utils.c */
void	ft_free(char **str);
int		ft_size(char **str);
void	ft_err(char *str, t_game *game);
void	ft_struct_game_free(t_game *game);
void	*safe_malloc(size_t	size);

/*validation*/
int		ft_str_col(char **map);
int		is_whitespace(char *str);
int		whitespace(char c);
int		start_end_wall(char *map);
int		mid_context_check(char **map, t_game *dir);
int		context_check(char context, t_game *dir, int x, int y);
int		check_wall(char *map, int len);
int		all_around_wall(char **map);
void	append_space_index(char **map, t_queue *q);
int		bfs(char **map);
int		validate_all(char *map_join, t_game *game);
/*map_validate_1.c*/
char	**freeall(char **str, int cnt);
int		word_cnt(char const *s);
int		word_len(char const *s);
char	*is_strdup(const char *s, int size);
int		check_extension(char *filename, char *str);
char	**is_split(char const *s);
int		cnt_info_flag(t_game *game, char *line);
char	*read_file(int fd, t_game *game);
void	read_map_info(char *str, t_game *game);
int		validate_all(char *map_join, t_game *game);
int		overlen_check(char **map);
//gnl
char	*get_next_line(int fd);
char	**ft_split2(char const *s, char c);
//init
t_game	*init_game(void);
int		over_len(char **map);
int		is_player_space(t_game *dir, char **map);
//key_handle.c
int		press_key(int keycode, t_game *game);
int		exit_game(t_game *game);

//raycatsing.c
int		draw_map(t_game *game, t_dinfo *dinfo);


#endif