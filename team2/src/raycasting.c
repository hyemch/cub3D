/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:09:45 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/22 17:06:30 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// draw_map(game->info, game->img, game->mlx, game->window);
//
//void	draw_map(t_game *info, t_img *img, void *m, void *w)
//{
//
//}

void	draw(t_game *game, t_dinfo *dinfo)
{
	int	x;
	int y;

	x = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			dinfo->timg->data[y * WIDTH + x] = info->buf[x][y];
			x++;
		}
		y++;
		mlx_put_image_to_window(game->mlx, game->window, dinfo->timg->img, 0, 0);
	}
}

int	main_loop(t_game *game, t_dinfo *dinfo)
{
	calc(dinfo);
	draw(game, dinfo);
	return (0);
}

void	load_image(t_game *game, t_dinfo *dinfo, int *texture, char *path)
{
	t_timg	timg;
	int		y;
	int		x;

	timg->img = mlx_xpm_file_to_image(game->mlx, path, &timg.img_width, &timg.img_height);
	timg.data = (int *) mlx_get_data_addr(timg.img, &timg->bpp, &timg.size_l, &timg.endian);
	y = 0;
	while (y < timg.img_height)
	{
		x = 0;
		while (x < timg.img_width)
		{
			texture[timg.img_width * y + x] = timg.data[timg.img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, timg.img);
}

void	load_texture(t_game *game, t_dinfo *dinfo)
{
	load_image (game, dinfo, dinfo->texture[0], "./asset/bluestone.xpm");
	load_image (game, dinfo, dinfo->texture[1], "./asset/colorstone.xpm");
	load_image (game, dinfo, dinfo->texture[2], "./asset/eagle.xpm");
	load_image (game, dinfo, dinfo->texture[3], "./asset/greystone.xpm");
	load_image (game, dinfo, dinfo->texture[4], "./asset/mossy.xpm");
	load_image (game, dinfo, dinfo->texture[5], "./asset/purplestone.xpm");
	load_image (game, dinfo, dinfo->texture[6], "./asset/redbrick.xpm");
	load_image (game, dinfo, dinfo->texture[7], "./asset/wood.xpm");
}

int	draw_map(t_game *game, t_dinfo *dinfo)
{
	int	i;
	int	j;

	dinfo->pos_x = game->info->p_pos[1];
	dinfo->pos_y = game->info->p_pos[0];
	dinfo->plane_x = 0.0;
	dinfo->plane_y = 0.66;
	dinfo->dir_x = -1.0;
	dinfo->dir_y = 0.0;
	dinfo->time = 0;
	dinfo->oldtime = 0;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			dinfo->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	dinfo->texture = (int **)malloc(sizeof(int *) * 8);
	if (!(dinfo->texture))
		return (-1);
	i = 0;
	while (i < 8)
	{
		dinfo->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!(dinfo->texture[i]))
			return (-1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < TEXWIDTH * TEXHEIGHT)
		{
			dinfo->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	load_texture(game, dinfo);
	dinfo->timg->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	dinfo->timg->data = (int *) mlx_get_data_addr(dinfo->timg->img, &dinfo->timg->bpp, &dinfo->timg->size_l, &dinfo->timg->endian);
	mlx_loop_hook(game.mlx, &main_loop, &dinfo);
}
