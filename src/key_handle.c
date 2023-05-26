/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:18:32 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/26 18:00:23 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	find_move(t_game *game)
{
	if (game->ray->key_l)
		find_rotate_left(game->ray);
	if (game->ray->key_r)
		find_rotate_right(game->ray);
	if (game->ray->key_w || game->ray->key_s || \
	game->ray->key_a || game->ray->key_d)
	{
		up_down_case(game);
		side_case(game);
	}
	else
		return (FALSE);
	return (TRUE);
}

int	cant_move_check(t_info *info, double y, double x)
{
	double	move;

	move = 0.05;
	if (info->map[(int)(y)][(int)(x)] == '1')
		return (FALSE);
	else if (info->map[(int)(y + move)][(int)(x)] == '1')
		return (FALSE);
	else if (info->map[(int)(y)][(int)(x + move)] == '1')
		return (FALSE);
	else if (info->map[(int)(y - move)][(int)(x)] == '1')
		return (FALSE);
	else if (info->map[(int)(y)][(int)(x - move)] == '1')
		return (FALSE);
	else if (info->map[(int)(y + move)][(int)(x - move)] == '1')
		return (FALSE);
	else if (info->map[(int)(y + move)][(int)(x + move)] == '1')
		return (FALSE);
	else if (info->map[(int)(y - move)][(int)(x + move)] == '1')
		return (FALSE);
	else if (info->map[(int)(y - move)][(int)(x - move)] == '1')
		return (FALSE);
	return (TRUE);
}

int	press_key(t_game *game)
{
	t_info		*info;
	double		b_pos[2];

	info = game->info;
	b_pos[0] = info->p_pos[0];
	b_pos[1] = info->p_pos[1];
	if (!find_move(game))
		return (FALSE);
	return (0);
}
