/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:51:44 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:51:44 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

int	mid_context_check(char **map, t_game *dir)
{
	int	i;
	int	j;
	int	col;

	col = ft_str_col(map);
	i = 1;
	while (map[i] && i < col)
	{
		j = 0;
		while (map[i][j])
		{
			if (!context_check(map[i][j], dir, j, i))
				return (FALSE);
			j++;
		}
		i++;
	}
	if (dir->info->player != 1)
	{
		ft_err("player count err", dir);
		return (FALSE);
	}
	return (TRUE);
}

int	all_around_wall(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_str_col(map);
	while (map[i])
	{
		if (i == 0 || i == len - 1)
		{
			if (start_end_wall(map[i]) == FALSE)
				return (FALSE);
		}
		else
		{
			if (check_wall(map[i], ft_strlen(map[i])) == FALSE)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	check_two_line(char **map, int i, int curr)
{
	while (map[i][curr])
	{
		if (map[i][curr] != ' ' && map[i][curr] != '1')
			return (FALSE);
		curr++;
	}
	return (TRUE);
}

int	overlen_check(char **map)
{
	int	next;
	int	curr_len;
	int	i;
	int	len;

	next = 0;
	curr_len = 0;
	i = -1;
	len = ft_str_col(map);
	while (++i < len - 1)
	{
		curr_len = ft_strlen(map[i]);
		next = ft_strlen(map[i + 1]);
		if (curr_len > next)
		{
			if (!check_two_line(map, i, next))
				return (FALSE);
		}
		else if (curr_len < next)
		{
			if (!check_two_line(map, i + 1, curr_len))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	check_wall(char *map, int len)
{
	int	i;

	i = is_whitespace(map);
	if (map[i] == '1' || map[len - 1] != '1')
		return (TRUE);
	return (FALSE);
}
