/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foxu_hwan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:48:18 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/24 19:17:27 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//void	ver_line(t_game *game, int x, int y1, int y2)
//{
//	int	y;
//
//	y = y1;
//	while (y <= y2)
//	{
//		mlx_pixel_put(game->mlx, game->window, x, y, game->ray->color);
//		y++;
//	}
//}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			game->img->data[y * W + x] = game->ray->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
}

void	calculate(t_game *game)
{
	floor_casting(game);
	wall_casting(game);
}

int	main_loop(t_game *game)
{
	calculate(game);
	draw_map(game);
	return (0);
}

void	load_image(t_game *game, int *texture, void *xpm_img)
{
	t_img	*img;
	int		x;
	int		y;

	img = game->img;
	img->data = (int *)mlx_get_data_addr(xpm_img, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[img->width * y + x] = img->data[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, xpm_img);
}

void	load_texture(t_game *game)
{
	load_image(game, game->ray->texture[0], game->img->north);
	load_image(game, game->ray->texture[1], game->img->south);
	load_image(game, game->ray->texture[2], game->img->west);
	load_image(game, game->ray->texture[3], game->img->east);
}

void	init_dir(t_game *game)
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

void	init_buf(t_game *game)
{
	int	i;

	i = 0;
	game->ray->buf = (int **)malloc(sizeof(int *) * (H + 1));
	while (i < H)
	{
		game->ray->buf[i] = (int *)malloc(sizeof(int) * W + 1);
		ft_memset(game->ray->buf[i], 0, W);
		game->ray->buf[i][W] = '\0';
		i++;
	}
	game->ray->buf[i] = NULL;
	game->ray->texture = (int **)malloc(sizeof(int *) * 5);
	i = 0;
	while (i < 5)
	{
		game->ray->texture[i] = (int *)malloc(sizeof(int) * (64 * 64));
		ft_memset(game->ray->texture[i], 0, (64 * 64));
		game->ray->texture[i][64 * 64] = '\0';
		i++;
	}
	game->ray->texture[i] = NULL;
}

void	ray_main(t_game *game)
{
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	ft_memset(game->ray, 0, sizeof(t_ray));
	game->ray->planeX = 0.0;
	game->ray->planeY = 0.66;
	game->ray->move_speed = 0.05;
	game->ray->rot_speed = 0.05;

	init_buf(game);
	init_dir(game);
	load_texture(game);

	game->img->img = mlx_new_image(game->mlx, W, H);
	game->img->data = (int *)mlx_get_data_addr(game->img->img, &game->img->bpp, &game->img->size_l, &game->img->endian);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_hook(game->window, 2, 0, press_key, game);
	mlx_loop(game->mlx);
	// printf("!!!!!!!!!\n");
}
