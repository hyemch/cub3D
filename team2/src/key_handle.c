/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:49:23 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/22 16:24:17 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

static int	find_move_position(t_info *info, int keycode)
{
	if (keycode == KEY_W)
		info->p_pos[0]--;
	else if (keycode == KEY_A)
		info->p_pos[1]--;
	else if (keycode == KEY_S)
		info->p_pos[0]++;
	else if (keycode == KEY_D)
		info->p_pos[1]++;
	/*
	else if (keycode == KEY_LEFT)
		raycast();
	else if (keycode == KEY_RIGHT)
		raycast();
	*/
	else
		return (FALSE);
	return (TRUE);
}

static int	cant_move_forward(t_info *info, int b_pos[])
{
	if (info->map[info->p_pos[0]][info->p_pos[1]] == '1')
	{
		info->p_pos[0] = b_pos[0];
		info->p_pos[1] = b_pos[1];
		return (FALSE);
	}
	return (TRUE);
}

int	press_key(int keycode, t_game *game)
{
	t_info	*info;
	t_dinfo	*dinfo;
	int		b_pos[2];

	info = game->info;
	dinfo = game->dinfo;
	b_pos[0] = info->p_pos[0];
	b_pos[1] = info->p_pos[1];
	if (keycode == KEY_ESC)
		exit_game(game);
	if (!find_move_position(info, keycode))
		return (0);
	if (!cant_move_forward(game->info, b_pos))
		return (0);
	else if (info->map[info->p_pos[0]][info->p_pos[1]] != '1')
	{
		info->map[b_pos[0]][b_pos[1]] = '0';
		info->map[info->p_pos[0]][info->p_pos[1]] = 'P';
		printf("%d %d\n", info->p_pos[0], info->p_pos[1]);
		draw_map(game, dinfo);
	}
	return (0);
}
