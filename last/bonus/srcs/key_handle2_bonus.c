/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:23:04 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/29 16:51:31 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_game(game);
	exit(0);
}

void	find_rotate_left(t_ray *ray)
{
	double	olddirx;
	double	oldplanex;

	olddirx = ray->dir_x;
	oldplanex = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(ray->rot_speed) \
				- ray->dir_y * sin(ray->rot_speed);
	ray->dir_y = olddirx * sin(ray->rot_speed) \
				+ ray->dir_y * cos(ray->rot_speed);
	ray->plane_x = ray->plane_x * cos(ray->rot_speed) \
				- ray->plane_y * sin(ray->rot_speed);
	ray->plane_y = oldplanex * sin(ray->rot_speed) \
				+ ray->plane_y * cos(ray->rot_speed);
}

void	find_rotate_right(t_ray *ray)
{
	double	olddirx;
	double	oldplanex;

	olddirx = ray->dir_x;
	oldplanex = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(-ray->rot_speed) \
				- ray->dir_y * sin(-ray->rot_speed);
	ray->dir_y = olddirx * sin(-ray->rot_speed) \
				+ ray->dir_y * cos(-ray->rot_speed);
	ray->plane_x = ray->plane_x * cos(-ray->rot_speed) \
				- ray->plane_y * sin(-ray->rot_speed);
	ray->plane_y = oldplanex * sin(-ray->rot_speed) \
				+ ray->plane_y * cos(-ray->rot_speed);
}
