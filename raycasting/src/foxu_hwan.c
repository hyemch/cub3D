/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foxu_hwan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:48:18 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/23 17:50:00 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ver_line(t_game *game, int x, int y1, int y2)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(game->mlx, game->window, x, y, game->ray->color);
		y++;
	}
}

void	calculate(t_game *game)
{
	int		x;
	int		map_x;
	int		map_y;
	t_ray	*ray;

	x = 0;
	ray = game->ray;
	while (x < W)
	{
		ray->cameraX = 2 * x / (double)W - 1;
		ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
		map_x = (int)game->info->p_pos[1];
		map_y = (int)game->info->p_pos[0];
		ray->deltaDistX = fabs(1 / ray->rayDirX);
		ray->deltaDistY = fabs(1 / ray->rayDirY);
		ray->hit = 0;
		if (ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (game->info->p_pos[1] - map_x) * ray->deltaDistX;
		}
		else
		{ 
			ray->stepX = 1;
			ray->sideDistX = (map_x + 1.0 - game->info->p_pos[1]) * ray->deltaDistX;
		}
		if (ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (game->info->p_pos[0] - map_y) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (map_y + 1.0 - game->info->p_pos[0]) * ray->deltaDistY;
		}
		while (ray->hit == 0)
		{
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				map_x += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				map_y += ray->stepY;
				ray->side = 1;
			}
			if (game->info->map[map_y][map_x] == '1')
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perpWallDist = (map_x - game->info->p_pos[1] + (1 - ray->stepX) / 2) / ray->rayDirX;
		else
			ray->perpWallDist = (map_y - game->info->p_pos[0] + (1 - ray->stepY) / 2) / ray->rayDirY;
		ray->line_height = (int)(H / ray->perpWallDist);
		ray->draw_start = H / 2 - (ray->line_height / 2);
        if (ray->draw_start < 0)
            ray->draw_start = 0;
		ray->draw_end = H / 2 + (ray->line_height / 2);
		if (ray->draw_end >= H)
			ray->draw_end = H - 1;
		if (game->info->map[map_y][map_x] == '1')
			ray->color = 0x00FF22;
		else
			ray->color = 0xFFFF00;
		if (ray->side == 1)
			ray->color = ray->color / 2;
		ver_line(game, x, ray->draw_start, ray->draw_end);
		x++;
	}
}

int main_loop(t_game *game)
{
	calculate(game);
	return (0);
}


void    init_dir(t_game *game)
{
    if (game->info->w == 1)
    {
        game->ray->dirX = -1.0;
        game->ray->dirY = 0.0;
    }
    else if (game->info->e == 1)
    {
        game->ray->dirX = 1.0;
        game->ray->dirY = 0.0;
    }
    else if (game->info->s == 1)
    {
        game->ray->dirX = 0.0;
        game->ray->dirY = -1.0;
    }
    else if (game->info->n == 1)
    {
        game->ray->dirX = 0.0;
        game->ray->dirY = 1.0;
    }
}

void ray_main(t_game *game)
{
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	ft_memset(game->ray, 0, sizeof(t_ray));
	game->ray->planeX = 0.0;
	game->ray->planeY = 0.66;
	game->ray->move_speed = 0.05;
	game->ray->rot_speed = 0.05;

    init_dir(game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_hook(game->window, 2, 0, press_key, game);
	mlx_loop(game->mlx);
}
/*
dir
*/