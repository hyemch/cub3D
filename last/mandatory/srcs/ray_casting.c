/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:45:10 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/29 16:53:07 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	get_rgb_color(int arr[])
{
	int	rgb;

	rgb = arr[0] * 65536 + arr[1] * 256 + arr[2];
	return (rgb);
}

void	floor_casting(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			game->ray->buf[y][x] = get_rgb_color(game->info->f);
			game->ray->buf[H - y - 1][x] = get_rgb_color(game->info->c);
			x++;
		}
		y++;
	}
}

void	wall_casting(t_game *game)
{
	int		x;

	x = 0;
	while (x < W)
	{
		set_ray_values(game, x);
		set_side_dist(game, game->info->p_pos[0], game->info->p_pos[1]);
		set_hit_values(game);
		set_textures_values(game);
		set_colors_values(game, x);
		x++;
	}
}
