/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:51:44 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/23 14:41:18 by yongmipa         ###   ########seoul.kr  */
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

int	overlen_check(char **map)
{
	int	next;
	int	curr_len;
	int	i;
	int	len;
	
	next = 0;
	curr_len = 0;
	i = 0;
	len = ft_str_col(map);
	while (i < len - 1)
	{
		curr_len = ft_strlen(map[i]);
		next = ft_strlen(map[i + 1]);
		if (curr_len > next) // next가 더 짧네?
		{
			while (map[i][next])
			{
				if (map[i][next] != ' ' && map[i][next] != '1')
				{
					// printf("i : %d next :%d", i, next);
					return (FALSE);
				}
				next++;
			}
		}
		else if (curr_len < next)
		{
			while (map[i + 1][curr_len])
			{
				if (map[i + 1][curr_len] != ' ' && map[i + 1][curr_len] != '1')
				{
					// printf("i + 1 : %d curlen : %d", i + 1, curr_len);
					return (FALSE);
				}
				curr_len++;
			}
		}
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
