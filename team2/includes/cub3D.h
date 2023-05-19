/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:17:25 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/19 17:19:22 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define TRUE 1
# define FALSE 0
# define DESTROY_NOTIFY 17

# include "queue.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_info // 맵에 대한 정보 담긴 구조체
{
	char	**map;
	int		info_flag[6];
	int		w;
	int		e;
	int		s;
	int		n;
	int		p_pos[2];
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
void		read_map_info(char *str, t_game *game);
int		validate_all(char *map_join, t_game *game);

//gnl
char	*get_next_line(int fd);
char	**ft_split2(char const *s, char c);
//init
t_game	*init_game(void);
int	over_len(char **map);


#endif