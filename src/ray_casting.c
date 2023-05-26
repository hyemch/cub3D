/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:45:10 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/26 17:58:33 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

	// floor->DirX0 = game->ray->dir_x - game->ray->plane_x;
	// floor->DirY0 = game->ray->dir_y - game->ray->plane_y;
	// floor->DirX1 = game->ray->dir_x + game->ray->plane_x;
	// floor->DirY1 = game->ray->dir_y + game->ray->plane_y;
	// floor->rowDist = (float)(0.5 * H) / (int)(y - (H / 2));
	// floor->floorStepX = floor->rowDist * (floor->DirX1 - floor->DirX0) / W;
	// floor->floorStepY = floor->rowDist * (floor->DirY1 - floor->DirY0) / W;
	// floor->floorX = game->info->p_pos[1] + floor->rowDist * floor->DirX0;
	// floor->floorY = game->info->p_pos[0] + floor->rowDist * floor->DirY0;
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
