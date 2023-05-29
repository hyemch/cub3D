/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:17:38 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/29 16:51:54 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->ray->buf[i])
		free(game->ray->buf[i++]);
	free(game->ray->buf);
	i = 0;
	while (game->ray->texture[i])
		free(game->ray->texture[i++]);
	free(game->ray->texture);
	ft_free(game->info->map);
	free(game->ray);
	free(game->wall);
	free(game->info);
	free(game->img);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	*safe_malloc(size_t	size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		ft_putendl_fd("malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

void	ft_err(char *str, t_game *game)
{
	if (game)
	{	
		free(game->info);
		free(game->img);
		free(game->ray);
		free(game->wall);
	}
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}
