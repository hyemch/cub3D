/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:19:07 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/15 18:01:48 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include "../includes/cub3D.h"

int	cnt_info_flag(t_game *game)
{
	int i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 6)
	{
		if (game->info_flag[i] == 1)
			cnt++;
		i++;
	}
	return (cnt);
}

char	*read_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*join;

	join = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_err("Failed to open file");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (cnt_info_flag(game) == 6)
			join = ft_strjoin(join, line);
		if (cnt_info_flag(game) != 6 && *line != '\n')
			read_map_info(line, game);
		free(line);
	}
	close(fd);
	return (join);
}

static void	init_texture(char **str, t_game *game, int type)
{
	if (ft_size(str) != 2)
		ft_err("File not found");
	if (type == 1)
	{
		game->info_flag[0] = 1;
		game->img->north = str[1]; // mlx_xpm_file_to_image 로 이어줘야하는지 몰겠음...
	}
	else if (type == 2)
	{
		game->info_flag[1] = 2;
		game->img->south = str[1];
	}
	else if (type == 3)
	{
		game->info_flag[2] = 1;
		game->img->west = str[1];
	}
	else if (type == 4)
	{
		game->info_flag[3] = 1;
		game->img->east = str[1];
	}
}

static void	init_color(char **str, t_game *game, int type)
{
	int	r;
	int	g;
	int	b;

	if (ft_size(str) != 3)
		ft_err("we need 3 color");
	r = ft_atoi(str[1]);
	g = ft_atoi(str[2]);
	b = ft_atoi(str[3]);
	if (r == -1 || g == -1 || b == -1)
		ft_err("Color range (0 ~ 255)");
	if (type == 5)
	{
		game->info_flag[4] = 1;
		game->map->f[0] = r;
		game->map->f[1] = g;
		game->map->f[2] = b;
	}
	else
	{
		game->info_flag[5] = 1;
		game->map->c[0] = r;
		game->map->c[1] = g;
		game->map->c[2] = b;
	}
}

int	read_map_info(char *str, t_game *game)
{
	char	**temp;
	// 순서도 맞춰야한대여
	temp = ft_split(str); // split 고쳤는데 테스트 해봐야함. split 고치면서 ft_strchr 도 고침 같이 확인 필요...
	if (!temp)
		ft_err("split");
	if (!ft_strncmp(temp[0], "NO", 2))
		init_texture(temp, game, 1);
	else if (!ft_strncmp(temp[0], "SO", 2))
		init_texture(temp, game, 2);
	else if (!ft_strncmp(temp[0], "WE", 2))
		init_texture(temp, game, 3);
	else if (!ft_strncmp(temp[0], "EA", 2))
		init_texture(temp, game, 4);
	else if (!ft_strncmp(temp[0], "F", 1))
		init_color(temp, game, 5);
	else if (!ft_strncmp(temp[0], "C", 1))
		init_color(temp, game, 6);
	else
	{
		ft_free(temp);
		ft_err("map info error\n");
	}
	ft_free(temp);
	return (0);
}
