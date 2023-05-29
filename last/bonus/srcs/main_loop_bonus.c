/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:07:22 by hyecheon          #+#    #+#             */
/*   Updated: 2023/05/29 16:51:33 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

static void	draw_map(t_game *game)
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

int	main_loop(t_game *game)
{
	floor_casting(game);
	wall_casting(game);
	draw_map(game);
	press_key(game);
	return (0);
}

static void	load_image(t_game *game, int *texture, void *xpm_img)
{
	t_img	*img;
	int		x;
	int		y;

	img = game->img;
	img->data = (int *)mlx_get_data_addr(xpm_img, &img->bpp,
			&img->size_l, &img->endian);
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

static void	load_texture(t_game *game)
{
	load_image(game, game->ray->texture[0], game->img->north);
	load_image(game, game->ray->texture[1], game->img->south);
	load_image(game, game->ray->texture[2], game->img->west);
	load_image(game, game->ray->texture[3], game->img->east);
}

void	raycasting(t_game *game)
{
	init_buf(game);
	init_dir(game);
	load_texture(game);
	game->img->img = mlx_new_image(game->mlx, W, H);
	game->img->data = (int *)mlx_get_data_addr(game->img->img, &game->img->bpp,
			&game->img->size_l, &game->img->endian);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_hook(game->window, X_EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->window, X_EVENT_KEY_RELEASE, 0, key_release, game->ray);
	mlx_hook(game->window, X_EVENT_MOUSE_MOVE, 0, mouse_handle, game);
	mlx_hook(game->window, DESTROY_NOTIFY, 0, exit_game, game);
	mlx_loop(game->mlx);
}
