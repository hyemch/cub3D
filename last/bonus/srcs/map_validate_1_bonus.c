/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:19:07 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:51:38 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

char	*read_file(int fd, t_game *game)
{
	char	*line;
	char	*join;
	char	*tmp;

	join = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (cnt_info_flag(game, line) == 6)
		{
			tmp = join;
			join = ft_strjoin(join, line);
			free(tmp);
		}
		else
			read_map_info(line, game);
		free(line);
	}
	return (join);
}

void	init_texture(char **str, t_game *game, int type)
{
	check_init_texture(str, game);
	if (type == 1)
	{
		game->img->north = mlx_xpm_file_to_image(game->mlx, str[1],
				&game->img->width, &game->img->height);
		game->info->info_flag[0]++;
	}
	else if (type == 2)
	{
		game->img->south = mlx_xpm_file_to_image(game->mlx, str[1],
				&game->img->width, &game->img->height);
		game->info->info_flag[1]++;
	}
	else if (type == 3)
	{
		game->img->west = mlx_xpm_file_to_image(game->mlx, str[1],
				&game->img->width, &game->img->height);
		game->info->info_flag[2]++;
	}
	else if (type == 4)
	{
		game->img->east = mlx_xpm_file_to_image(game->mlx, str[1],
				&game->img->width, &game->img->height);
		game->info->info_flag[3]++;
	}
}

void	check_color(int *map_info, char **color, t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		map_info[i] = ft_atoi(color[i]);
		if (map_info[i] < 0 || 255 < map_info[i])
		{
			ft_free(color);
			ft_err("Color range (0 ~ 255)", game);
		}
		i++;
	}
}

void	init_color(char **str, t_game *game, int type)
{
	char	**color;

	if (ft_str_col(str) != 2)
	{
		ft_free(str);
		ft_err("information", game);
	}
	if (!comma_getsu_is_ok(str[1]))
	{
		ft_free(str);
		ft_err("to many comma", game);
	}
	color = ft_split(str[1], ',');
	if (!color)
	{
		ft_free(str);
		ft_err("malloc", game);
	}
	validate_color(str, color, game, type);
	ft_free(color);
}

void	read_map_info(char *str, t_game *game)
{
	char	**temp;

	temp = is_split(str);
	if (!temp)
	{
		free(str);
		ft_err("malloc failed", game);
	}
	if (temp[0])
		valid_case(temp, game);
	ft_free(temp);
}
