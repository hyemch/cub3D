/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:35:04 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 17:00:50 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	img_check(char *map_join, t_game *game)
{
	if (!game->img->north || !game->img->south
		|| !game->img->east || !game->img->west)
	{
		free(map_join);
		ft_err("image path", game);
	}
}

int	validate_all(char *map_join, t_game *game)
{
	char	**map;

	img_check(map_join, game);
	map = ft_split2(map_join, '\n');
	if (!map)
	{
		free(map_join);
		return (FALSE);
	}
	if (all_around_wall(map) && mid_context_check(map, game) \
		&& is_player_space(game, map) && overlen_check(map) && bfs(map))
	{
		free(map_join);
		game->info->map = map;
		return (TRUE);
	}
	free(map_join);
	ft_free(map);
	return (FALSE);
}
