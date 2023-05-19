/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:35:04 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/19 17:12:10 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	validate_all(char *map_join, t_game *game)
{
	char	**map;

	// if (!game->img->north || !game->img->south || !game->img->east || !game->img->west)
	// 	return (FALSE);
	map = ft_split2(map_join, '\n');
	if (!map)
		return (FALSE);
	if (bfs(map) && over_len(map) && all_around_wall(map)
		&& mid_context_check(map, game))
	{
		free(map_join);
		game->info->map = map;
		return (TRUE);
	}
	free(map_join);
	ft_free(map);
	return (FALSE);
}
