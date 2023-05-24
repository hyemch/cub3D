#include "../includes/cub3D.h"

void	calc2(t_game *game)
{
	int		x;
	int		y;
	t_ray	*ray;

	ray = game->ray;
	x = 0;
	y = 0;
	while (y < H)
	{
		ray->rayDirX0 = ray->dirX - ray->planeX;
		ray->rayDirY0 = ray->dirY - ray->planeY;
		ray->rayDirX = ray->dirX + ray->planeX;
		ray->rayDirY = ray->dirY + ray->planeY;
		y++;
	}
}