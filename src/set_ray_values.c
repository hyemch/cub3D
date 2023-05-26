/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:10:20 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/26 17:58:56 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	set_ray_values(t_game *game, int x)
{
	t_ray	*ray;

	ray = game->ray;
	ray->map_x = (int)game->info->p_pos[1];
	ray->map_y = (int)game->info->p_pos[0];
	ray = game->ray;
	ray->camera_x = 2 * x / (double)W - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	set_side_dist(t_game *game, double y, double x)
{
	t_ray	*ray;

	ray = game->ray;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - y) * ray->delta_dist_y;
	}
}

void	set_draw_values(t_game *game)
{
	t_ray	*ray;

	ray = game->ray;
	if (ray->side == 0)
	{
		ray->perp_wall_dist = ((ray->map_x - game->info->p_pos[1])
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	}
	else
	{
		ray->perp_wall_dist = ((ray->map_y - game->info->p_pos[0])
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	}
	ray->line_height = (int)(H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + H / 2 ;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = H / 2 + (ray->line_height / 2);
	if (ray->draw_end >= H)
		ray->draw_end = H - 1;
}

void	set_wall_values(t_game *game)
{
	t_ray	*ray;
	t_wall	*wall;

	ray = game->ray;
	wall = game->wall;
	if (ray->side == 0)
		wall->wall_x = game->info->p_pos[0] \
		+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall->wall_x = game->info->p_pos[1] \
		+ ray->perp_wall_dist * ray->ray_dir_x;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex_x = (int)(wall->wall_x * (double)64);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		wall->tex_x = 64 - wall->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		wall->tex_x = 64 - wall->tex_x - 1;
	wall->step = 1.0 * 64 / ray->line_height;
	wall->tex_pos = (ray->draw_start - H / 2 + ray->line_height / 2)
		* wall->step;
}

void	set_colors_values(t_game *game, int x)
{
	t_ray	*ray;
	t_wall	*wall;
	int		y;

	ray = game->ray;
	wall = game->wall;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		wall->tex_y = (int)wall->tex_pos & (64 - 1);
		wall->tex_pos += wall->step;
		if (ray->side == 0 && ray->ray_dir_x > 0)
			ray->color = ray->texture[3][wall->tex_y * 64 + wall->tex_x];
		else if (ray->side == 0 && ray->ray_dir_x < 0)
			ray->color = ray->texture[2][wall->tex_y * 64 + wall->tex_x];
		else if (ray->side == 1 && ray->ray_dir_y > 0)
			ray->color = ray->texture[0][wall->tex_y * 64 + wall->tex_x];
		else if (ray->side == 1 && ray->ray_dir_y < 0)
			ray->color = ray->texture[1][wall->tex_y * 64 + wall->tex_x];
		ray->buf[y][x] = ray->color;
		y++;
	}
}
