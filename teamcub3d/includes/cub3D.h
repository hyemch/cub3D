/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:17:25 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/24 17:10:58 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 10000

# define KEY_PRESS				2
# define DESTROY_NOTIFY			17
# define K_ESC					53
# define K_W					13
# define K_A					0
# define K_S					1
# define K_D					2
# define K_L					123
# define K_R					124
# define INVALID_KEYCODE		0
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17


# define TRUE 1
# define FALSE 0
# define W 1280
# define H 920

# include "queue.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_ray
{
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	move_speed;
	double	rot_speed;
	double	cameraX;
	double 	rayDirX;
	double 	rayDirY;
		//length of ray from current position to next x or y-side
	double 	sideDistX;
	double 	sideDistY;
		
	//length of ray from one x or y-side to next x or y-side
	double 	deltaDistX;
	double 	deltaDistY;
	double 	perpWallDist;
		
	//what direction to step in x or y-direction (either +1 or -1)
	int		stepX;
	int		stepY;
	
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	
	int		hit;
	int		side;

	int		**buf;
	int		**texture;
	// 여기서 부터는 내꺼 ------
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_a;
	int		key_l;
	int		key_r;
}	t_ray;

typedef struct s_info // 맵에 대한 정보 담긴 구조체
{
	char	**map;
	int		info_flag[6];
	int		w;
	int		e;
	int		s;
	int		n;
	double	p_pos[2];
	int		player;
	int		f[3];
	int		c[3];
}	t_info;

typedef struct s_floor
{
	float	DirX0;
	float	DirX1;
	float	DirY0;
	float	DirY1;

	float	rowDist;

	float	floorStepX;
	float	floorStepY;

	float	floorX;
	float	floorY;
}	t_floor;

typedef struct s_wall
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int	tex_y;
	double	floor_x_wall;
	double	floor_y_wall;
	
	double	dist_wall;
	double	dist_p;
	double	curr_dist;

	double	weight;
	double	curr_floor_x;
	double	curr_floor_y;

	int		floor_tex_x;
	int		floor_tex_y;
	int		check_borad;
	int		floor_tex;
}	t_wall;


typedef struct s_img //이미지, 해상도 담긴 구조체
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*img;

	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
	int		*data;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_img	*img;
	t_info	*info;
	t_ray	*ray;
	t_floor	*floor;
	t_wall	*wall;
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
int		find_move(t_game *game, int keycode);
void	find_move_position(t_game *game, int keycode);
int		press_key(int keycode, t_game *game);
int		exit_game(t_game *game);

//ray_cast
void ray_main(t_game *game);
int main_loop(t_game *game);
void	floor_casting(t_game *game);
void	wall_casting(t_game *game);
#endif