/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:12:53 by hyecheon          #+#    #+#             */
/*   Updated: 2023/05/29 17:12:07 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define X_EVENT_MOUSE_MOVE		6

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
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		hit;
	int		side;
	int		**buf;
	int		**texture;
	int		map_x;
	int		map_y;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_a;
	int		key_l;
	int		key_r;
}	t_ray;

typedef struct s_info
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

typedef struct s_wall
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
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

typedef struct s_img
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
	t_wall	*wall;
}	t_game;

void	ft_free(char **str);
void	ft_err(char *str, t_game *game);
void	*safe_malloc(size_t	size);
void	free_game(t_game *game);

int		ft_str_col(char **map);
int		is_whitespace(char *str);
int		start_end_wall(char *map);
int		mid_context_check(char **map, t_game *dir);
int		context_check(char context, t_game *dir, int x, int y);
int		check_wall(char *map, int len);
int		all_around_wall(char **map);
void	append_space_index(char **map, t_queue *q);
int		bfs(char **map);
int		validate_all(char *map_join, t_game *game);
char	**make_words(const char *s, char c, int i, char **word);
void	img_check(char *map_join, t_game *game);

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
int		is_player_space(t_game *dir, char **map);
void	check_color(int *map_info, char **color, t_game *game);
void	init_texture(char **str, t_game *game, int type);
void	init_color(char **str, t_game *game, int type);

void	check_init_texture(char **str, t_game *game);
void	validate_color(char **str, char **color, t_game *game, int type);
void	valid_case(char **temp, t_game *game);

int		key_press(int key, t_game *game);
int		key_release(int key, t_ray *ray);

char	*get_next_line(int fd);
char	**ft_split2(char const *s, char c);

t_game	*init_game(void);
void	init_dir(t_game *game);
void	init_buf(t_game *game);

int		mouse_handle(int x, int y, t_game *game);

int		find_move(t_game *game);
void	press_key(t_game *game);
int		exit_game(t_game *game);
void	find_rotate_right(t_ray *ray);
void	find_rotate_left(t_ray *ray);
int		cant_move_check(t_info *info, double y, double x);

void	up_down_case(t_game *game);
void	side_case(t_game *game);

void	raycasting(t_game *game);
int		main_loop(t_game *game);
void	floor_casting(t_game *game);
void	wall_casting(t_game *game);
void	set_ray_values(t_game *game, int x);
void	set_side_dist(t_game *game, double y, double x);
void	set_draw_values(t_game *game);
void	set_wall_values(t_game *game);
void	set_colors_values(t_game *game, int x);
void	set_hit_values(t_game *game);
void	set_textures_values(t_game *game);
int		comma_getsu_is_ok(char *str);

#endif
