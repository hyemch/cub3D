/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:34:52 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/26 17:52:39 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	up_down_case(t_game *game)
{
	t_ray	*ray;
	double	y;
	double	x;

	ray = game->ray;
	y = game->info->p_pos[0];
	x = game->info->p_pos[1];
	if (ray->key_w)
	{
		if (cant_move_check(game->info, y, x + ray->dir_x * ray->move_speed))
			game->info->p_pos[1] += ray->dir_x * ray->move_speed;
		if (cant_move_check(game->info, y + ray->dir_y * ray->move_speed, x))
			game->info->p_pos[0] += ray->dir_y * ray->move_speed;
	}
	if (ray->key_s)
	{
		if (cant_move_check(game->info, y, x - ray->dir_x * ray->move_speed))
			game->info->p_pos[1] -= ray->dir_x * ray->move_speed;
		if (cant_move_check(game->info, y - ray->dir_y * ray->move_speed, x))
			game->info->p_pos[0] -= ray->dir_y * ray->move_speed;
	}
}

void	side_case(t_game *game)
{
	t_ray	*ray;
	double	y;
	double	x;

	ray = game->ray;
	y = game->info->p_pos[0];
	x = game->info->p_pos[1];
	if (ray->key_a)
	{
		if (cant_move_check(game->info, y, x - (ray->dir_y * ray->move_speed)))
			game->info->p_pos[1] -= ray->dir_y * ray->move_speed;
		if (cant_move_check(game->info, y + ray->dir_x * ray->move_speed, x))
			game->info->p_pos[0] += ray->dir_x * ray->move_speed;
	}
	if (ray->key_d)
	{
		if (cant_move_check(game->info, y, x + ray->dir_y * ray->move_speed))
			game->info->p_pos[1] += ray->dir_y * ray->move_speed;
		if (cant_move_check(game->info, y - (ray->dir_x * ray->move_speed), x))
			game->info->p_pos[0] -= ray->dir_x * ray->move_speed;
	}
}
