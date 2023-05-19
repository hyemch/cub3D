/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:51:44 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/19 15:51:59 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
				return (-1);
			j++;
		}
		i++;
	}
	if (dir->info->player != 1)
	{
		ft_err("player count err\n", dir);
		return (-1);
	}
	return (1);
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

int	over_len(char **map)
{
	int	prev_len;
	int	curr_len;
	int	i;

	prev_len = ft_strlen(map[0]);
	curr_len = 0;
	i = 0;
	while (map[i])
	{
		curr_len = ft_strlen(map[i]);
		if (curr_len > prev_len)
		{
			while (map[i][prev_len])
			{
				if (map[i][prev_len] != ' ' && map[i][prev_len] != '1')
					return (FALSE);
				prev_len++;
			}
		}
		prev_len = ft_strlen(map[i]);
		i++;
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
