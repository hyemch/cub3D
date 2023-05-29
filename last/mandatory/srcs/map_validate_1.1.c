/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_1.1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:46:06 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:53:03 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	validate_color(char **str, char **color, t_game *game, int type)
{
	if (ft_str_col(color) != 3)
	{
		ft_free(str);
		ft_free(color);
		ft_err("we need 3 color", game);
	}
	if (type == 5)
	{
		game->info->info_flag[4]++;
		check_color(game->info->f, color, game);
	}
	else
	{
		game->info->info_flag[5]++;
		check_color(game->info->c, color, game);
	}
}

void	valid_case(char **temp, t_game *game)
{
	if (!ft_strncmp(temp[0], "NO", 3))
		init_texture(temp, game, 1);
	else if (!ft_strncmp(temp[0], "SO", 3))
		init_texture(temp, game, 2);
	else if (!ft_strncmp(temp[0], "WE", 3))
		init_texture(temp, game, 3);
	else if (!ft_strncmp(temp[0], "EA", 3))
		init_texture(temp, game, 4);
	else if (!ft_strncmp(temp[0], "F", 2))
		init_color(temp, game, 5);
	else if (!ft_strncmp(temp[0], "C", 2))
		init_color(temp, game, 6);
	else
	{
		ft_free(temp);
		ft_err("map info error", game);
	}
}

void	check_init_texture(char **str, t_game *game)
{
	if (ft_str_col(str) != 2)
	{
		ft_free(str);
		ft_err("infomation", game);
	}
	if (!check_extension(str[1], ".xpm"))
	{
		ft_free(str);
		ft_err("img extention must .xpm", game);
	}
}

int	comma_getsu_is_ok(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == ',')
			cnt++;
		i++;
	}
	if (cnt != 2)
		return (FALSE);
	return (TRUE);
}
