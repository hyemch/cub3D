/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:08:21 by hyecheon          #+#    #+#             */
/*   Updated: 2023/05/12 19:09:10 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	map_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename && filename[i] != '\0')
		i++;
	if (filename[i - 4] != '.' || filename[i - 3] != 'c' || \
		filename[i - 2] != 'u' || filename[i - 1] != 'b')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	(void)argv;
	if (argc != 2)
		return (write(2, "ERROR\nArgument count error\n", 27));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "cub3D");
//	mlx_loop_hook(game.mlx, draw_map, &game);
//	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, key_hook, &game);
//	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, exit_game, &game);
//	mlx_loop(game.mlx);
	return (0);
}