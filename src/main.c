/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:08:44 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/26 17:26:37 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char *av[])
{
	t_game	*game;
	int		fd;

	if (ac != 2)
		ft_err("invalid argument count", 0);
	if (!check_extension(av[1], ".cub"))
		ft_err("invalid file argument extention", 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_err("Failed to open file", 0);
	game = init_game();
	if (!validate_all(read_file(fd, game), game))
		ft_err("map error!", game);
	close(fd);
	game->window = mlx_new_window(game->mlx, W, H, "cub3D");
	game->info->map[(int)game->info->p_pos[0]][(int)game->info->p_pos[1]] = '0';
	raycasting(game);
	return (0);
}
