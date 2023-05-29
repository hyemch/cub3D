/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:06:01 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/29 16:52:53 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *)safe_malloc(sizeof(t_ray));
	ft_memset(ray, 0, sizeof(t_ray));
	ray->move_speed = 0.05;
	ray->rot_speed = 0.05;
	return (ray);
}

void	init_plane(t_game *game, double x, double y)
{
	game->ray->plane_x = x;
	game->ray->plane_y = y;
}

void	init_dir(t_game *game)
{
	if (game->info->w == 1)
	{
		game->ray->dir_x = -1.0;
		game->ray->dir_y = 0.0;
		init_plane(game, 0.0, 0.66);
	}
	else if (game->info->e == 1)
	{
		game->ray->dir_x = 1.0;
		game->ray->dir_y = 0.0;
		init_plane(game, 0.0, -0.66);
	}
	else if (game->info->n == 1)
	{
		game->ray->dir_x = 0.0;
		game->ray->dir_y = -1.0;
		init_plane(game, -0.66, 0);
	}
	else if (game->info->s == 1)
	{
		game->ray->dir_x = 0.0;
		game->ray->dir_y = 1.0;
		init_plane(game, 0.66, 0.0);
	}
}

void	init_buf(t_game *game)
{
	int	i;

	i = 0;
	game->ray->buf = (int **)malloc(sizeof(int *) * (H + 1));
	while (i < H)
	{
		game->ray->buf[i] = (int *)ft_calloc(sizeof(int), W);
		i++;
	}
	game->ray->buf[i] = NULL;
	game->ray->texture = (int **)malloc(sizeof(int *) * 5);
	i = 0;
	while (i < 5)
	{
		game->ray->texture[i] = (int *)ft_calloc(sizeof(int), (64 * 64));
		i++;
	}
	game->ray->texture[i] = NULL;
}

t_game	*init_game(void)
{
	t_game	*game;
	t_info	*info;
	t_img	*img;
	t_wall	*wall;

	game = (t_game *)safe_malloc(sizeof(t_game));
	info = (t_info *)safe_malloc(sizeof(t_info));
	img = (t_img *)safe_malloc(sizeof(t_img));
	wall = (t_wall *)safe_malloc(sizeof(t_wall));
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(info, 0, sizeof(t_info));
	ft_memset(img, 0, sizeof(t_img));
	ft_memset(wall, 0, sizeof(t_wall));
	game->info = info;
	game->img = img;
	game->ray = init_ray();
	game->wall = wall;
	game->mlx = mlx_init();
	return (game);
}
