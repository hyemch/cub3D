/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:17:25 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/16 17:31:45 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include "queue.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>



typedef struct s_map // 맵에 대한 정보 담긴 구조체
{
	char	**map;
	int		f[3];
	int		c[3];
}	t_map;

typedef struct s_img //이미지, 해상도 담긴 구조체
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		info_flag[6];
	int		w;
	int		a;
	int		s;
	int		d;
	t_img	img[4];
	t_map	map;
}	t_game;

/* utils.c */
void	ft_free(char **str);
int		ft_size(char **str);
int		ft_isspace(char c);
void	ft_err(char *str);

/*validation*/
int	ft_str_col(char **map);
int	is_whitespace(char *str);
int	whitespace(char c);
int	start_end_wall(char *map);
int	check_wall(char *map, int len);
int	all_around_wall(char **map); // 이차원이라 생각할게여
int	context_check(char context, t_game *dir);
int	mid_context_check(char **map, t_game *dir); //WASD, 1, 0만 있어야댐
void	append_space_index(char **map, t_queue *q);
int	bfs(char **map);

/*map_validate_1.c*/
int		word_cnt(char const *s);
int		word_len(char const *s);
char	*is_strdup(const char *s, int size);
int		read_map_info(char *str, t_game *game);
char	**freeall(char **str, int cnt);
char	**is_split(char const *s);
int		cnt_info_flag(t_game *game);
char	*read_file(int fd, t_game *game);
int		read_map_info(char *str, t_game *game);

//gnl
char	*get_next_line(int fd);


#endif