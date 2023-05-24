/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:49:23 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/24 19:37:06 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

static void	find_rotate_left(t_ray *ray)
{
	double	olddirx;
	double	oldplanex;

	olddirx = ray->dirX;
	oldplanex = ray->planeX;
	ray->dirX = ray->dirX * cos(ray->rot_speed) \
				- ray->dirY * sin(ray->rot_speed);
	ray->dirY = olddirx * sin(ray->rot_speed) \
				+ ray->dirY * cos(ray->rot_speed);
	ray->planeX = ray->planeX * cos(-ray->rot_speed) \
				- ray->planeY * sin(ray->rot_speed);
	ray->planeY = oldplanex * sin(ray->rot_speed) \
				+ ray->planeY * cos(ray->rot_speed);
}

static void	find_rotate_right(t_ray *ray)
{
	double	olddirx;
	double	oldplanex;

	olddirx = ray->dirX;
	oldplanex = ray->planeX;
	ray->dirX = ray->dirX * cos(-ray->rot_speed) \
				- ray->dirY * sin(-ray->rot_speed);
	ray->dirY = olddirx * sin(-ray->rot_speed) \
				+ ray->dirY * cos(-ray->rot_speed);
	ray->planeX = ray->planeX * cos(-ray->rot_speed) \
				- ray->planeY * sin(-ray->rot_speed);
	ray->planeY = oldplanex * sin(-ray->rot_speed) \
				+ ray->planeY * cos(-ray->rot_speed);
}

void	find_move_position(t_game *game, int keycode)
{
	t_ray	*ray;

	ray = game->ray;
	if (keycode == K_W)
	{
		if ((game->info->map[(int)game->info->p_pos[0]] \
		[(int)(game->info->p_pos[1] + ray->dirX * ray->move_speed)]) != '1')
			game->info->p_pos[1] += ray->dirX * ray->move_speed;
		if ((game->info->map[(int)(game->info->p_pos[0] + \
		ray->dirY * ray->move_speed)][(int)game->info->p_pos[1]]) != '1')
			game->info->p_pos[0] += ray->dirY * ray->move_speed;
	}
	else if (keycode == K_S)
	{
		if ((game->info->map[(int)game->info->p_pos[0]] \
		[(int)(game->info->p_pos[1] - ray->dirX * ray->move_speed)]) != '1')
			game->info->p_pos[1] -= ray->dirX * ray->move_speed;
		if ((game->info->map[(int)(game->info->p_pos[0] - \
		ray->dirY * ray->move_speed)][(int)game->info->p_pos[1]]) != '1')
			game->info->p_pos[0] -= ray->dirY * ray->move_speed;
	}
	else if (keycode == K_A)
	{
		if ((game->info->map[(int)game->info->p_pos[0]] \
		[(int)(game->info->p_pos[1] - ray->dirX * ray->move_speed)]) != '1')
			game->info->p_pos[1] += -ray->dirY * ray->move_speed;
		if ((game->info->map[(int)(game->info->p_pos[0] + \
		ray->dirY * ray->move_speed)][(int)game->info->p_pos[1]]) != '1')
			game->info->p_pos[0] += ray->dirX * ray->move_speed;
	}
	else if (keycode == K_D)
	{
		if ((game->info->map[(int)game->info->p_pos[0]] \
		[(int)(game->info->p_pos[1] + ray->dirX * ray->move_speed)]) != '1')
			game->info->p_pos[1] += ray->dirY * ray->move_speed;
		if ((game->info->map[(int)(game->info->p_pos[0] - \
		ray->dirY * ray->move_speed)][(int)game->info->p_pos[1]]) != '1')
			game->info->p_pos[0] += -ray->dirX * ray->move_speed;
	}
}

int	find_move(t_game *game, int keycode)
{
	if (keycode == K_W || keycode == K_S || \
	keycode == K_A || keycode == K_D)
		find_move_position(game, keycode);
	if (keycode == K_L)
		find_rotate_left(game->ray);
	else if (keycode == K_R)
		find_rotate_right(game->ray);
	else
		return (FALSE);
	return (TRUE);
}

static int	cant_move_forward(t_info *info, double b_pos[])
{
	if (info->map[(int)info->p_pos[0]][(int)info->p_pos[1]] == '1')
	{
		info->p_pos[0] = b_pos[0];
		info->p_pos[1] = b_pos[1];
		return (FALSE);
	}
	return (TRUE);
}

int	press_key(int keycode, t_game *game)
{
	t_info		*info;
	double		b_pos[2];

	info = game->info;
	b_pos[0] = info->p_pos[0];
	b_pos[1] = info->p_pos[1];
	if (keycode == K_ESC)
		exit_game(game);
	if (!find_move(game, keycode))
		return (0);
	if (!cant_move_forward(game->info, b_pos))
		return (0);
	else if (info->map[(int)info->p_pos[0]][(int)info->p_pos[1]] != '1')
	{
		info->map[(int)b_pos[0]][(int)b_pos[1]] = '0';
		info->map[(int)info->p_pos[0]][(int)info->p_pos[1]] = 'P';
		// printf("%d %d\n",info->p_pos[0], info->p_pos[1]);
		// draw_map(game->info, game->img, game->mlx, game->window);
	}
	return (0);
}
