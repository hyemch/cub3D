/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:27:11 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:52:58 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	else if (key == K_W)
		game->ray->key_w = 1;
	else if (key == K_A)
		game->ray->key_a = 1;
	else if (key == K_S)
		game->ray->key_s = 1;
	else if (key == K_D)
		game->ray->key_d = 1;
	else if (key == K_L)
		game->ray->key_l = 1;
	else if (key == K_R)
		game->ray->key_r = 1;
	return (0);
}

int	key_release(int key, t_ray *ray)
{
	if (key == K_W)
		ray->key_w = 0;
	else if (key == K_A)
		ray->key_a = 0;
	else if (key == K_S)
		ray->key_s = 0;
	else if (key == K_D)
		ray->key_d = 0;
	else if (key == K_L)
		ray->key_l = 0;
	else if (key == K_R)
		ray->key_r = 0;
	return (0);
}
