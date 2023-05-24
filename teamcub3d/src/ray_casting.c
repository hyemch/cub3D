#include "../includes/cub3D.h"

void	floor_casting(t_game *game)
{
	int		x;
	int		y;
	t_floor	*floor;

	y = 0;
	floor = game->floor;

	while (y < H)
	{
		floor->DirX0 = game->ray->dirX - game->ray->planeX;
		floor->DirY0 = game->ray->dirY - game->ray->planeY;
		floor->DirX1 = game->ray->dirX + game->ray->planeX;
		floor->DirY1 = game->ray->dirY + game->ray->planeY;

		floor->rowDist = (float)(0.5 * H) / (int)(y - (H / 2));

		floor->floorStepX = floor->rowDist * (floor->DirX1 - floor->DirX0) / W;
		floor->floorStepY = floor->rowDist * (floor->DirY1 - floor->DirY0) / W;

		floor->floorX = game->info->p_pos[1] + floor->rowDist * floor->DirX0;
		floor->floorY = game->info->p_pos[0] + floor->rowDist * floor->DirY0;

		x = 0;
		while (x < W)
		{
			game->ray->buf[y][x] = 0xFF0000; //rgb값 각각 16진수 비트연산해서 넣기
			game->ray->buf[H - y - 1][x] = 0x00FF00;
			x++;
		}
		y++;
	}
}

void	wall_casting(t_game *game)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	t_ray	*ray;
	t_wall	*wall;

	x = 0;
	ray = game->ray;
	wall = game->wall;
	while (x < W)
	{
		ray->cameraX = 2 * x / (double)W - 1;
		ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
		map_x = (int)game->info->p_pos[1];
		map_y = (int)game->info->p_pos[0];
		ray->deltaDistX = fabs(1 / ray->rayDirX);
		ray->deltaDistY = fabs(1 / ray->rayDirY);
		ray->hit = 0;
		if (ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (game->info->p_pos[1] - map_x) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (map_x + 1.0 - game->info->p_pos[1]) * ray->deltaDistX;
		}
		if (ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (game->info->p_pos[0] - map_y) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (map_y + 1.0 - game->info->p_pos[0]) * ray->deltaDistY;
		}
		while (ray->hit == 0)
		{
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				map_x += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				map_y += ray->stepY;
				ray->side = 1;
			}
			if (game->info->map[map_y][map_x] == '1')
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perpWallDist = (map_x - game->info->p_pos[1] + (1 - ray->stepX) / 2) / ray->rayDirX;
		else
			ray->perpWallDist = (map_y - game->info->p_pos[0] + (1 - ray->stepY) / 2) / ray->rayDirY;
		ray->line_height = (int)(H / ray->perpWallDist);
		ray->draw_start = -ray->line_height / 2 + H / 2 ;
		if (ray->draw_start < 0)
			ray->draw_start = 0;
		ray->draw_end = H / 2 + (ray->line_height / 2);
		if (ray->draw_end >= H)
			ray->draw_end = H - 1;

		if (ray->side == 0)
			wall->wall_x = game->info->p_pos[0] + ray->perpWallDist * ray->rayDirY;
		else
			wall->wall_x = game->info->p_pos[1] + ray->perpWallDist * ray->rayDirX;
		wall->wall_x -= floor(wall->wall_x);
		wall->tex_x = (int)(wall->wall_x * (double)64);
		if (ray->side == 0 && ray->rayDirX > 0)
			wall->tex_x = 64 - wall->tex_x - 1;
		if (ray->side == 1 && ray->rayDirY < 0)
			wall->tex_x = 64 - wall->tex_x - 1;
		wall->step = 1.0 * 64 / ray->line_height;
		wall->tex_pos = (ray->draw_start - H / 2 + ray->line_height / 2) * wall->step;
		y = ray->draw_start;
		while (y < ray->draw_end)
		{
			wall->tex_y = (int)wall->tex_pos & (64 - 1);
			wall->tex_pos += wall->step;
			if (ray->side == 0 && ray->rayDirX > 0)
				ray->color = ray->texture[0][wall->tex_y * 64 + wall->tex_x];
			else if (ray->side == 0 && ray->rayDirX < 0)
				ray->color = ray->texture[1][wall->tex_y * 64 + wall->tex_x];
			else if (ray->side == 1 && ray->rayDirY > 0)
				ray->color = ray->texture[3][wall->tex_y * 64 + wall->tex_x];
			else if (ray->side == 1 && ray->rayDirY < 0)
				ray->color = ray->texture[2][wall->tex_y * 64 + wall->tex_x];
			ray->buf[y][x] = ray->color;
			y++;
		}
		x++;
//		if (ray->side == 0 && ray->rayDirX > 0)
//		{
//		wall->floor_x_wall = map_x;
//		wall->floor_y_wall = map_y + wall->wall_x;
//		}
//		else if (ray->side == 0 && ray->rayDirX < 0)
//		{
//		wall->floor_x_wall = map_x + 1.0;
//		wall->floor_y_wall = map_y + wall->wall_x;
//		}
//		else if (ray->side == 1 && ray->rayDirY > 0)
//		{
//		wall->floor_x_wall = map_x + wall->wall_x;
//		wall->floor_y_wall = map_y;
//		}
//		else
//		{
//		wall->floor_x_wall = map_x + wall->wall_x;
//		wall->floor_y_wall = map_y + 1.0;
//		}
//		wall->dist_wall = game->ray->perpWallDist;
//		wall->dist_p = 0.0;
//
//		if (game->ray->draw_end < 0)
//		game->ray->draw_end = H;
//		y = game->ray->draw_end + 1;
//		while (y < H)
//		{
//		wall->curr_dist = H / (2.0 * y - H);
//		wall->weight = (wall->curr_dist - wall->dist_p) / (wall->dist_wall - wall->dist_p);
//		wall->curr_floor_x = wall->weight * wall->floor_x_wall + (1.0 - wall->weight) * game->info->p_pos[1];
//		wall->curr_floor_y = wall->weight * wall->floor_y_wall + (1.0 - wall->weight) * game->info->p_pos[0];
//
//		wall->floor_tex_x = (int)(wall->curr_floor_x * 64) % 64;
//		wall->floor_tex_y = (int)(wall->curr_floor_y * 64) % 64;
//
//		// wall->check_borad = ((int)(wall->curr_floor_x) + (int)(wall->curr_floor_y)) % 2;
//		// if (wall->check_borad == 0)
//		// 	wall->floor_tex = 3;
//		// else
//		// 	wall->floor_tex = 4;
//		ray->buf[y][x] = ray->texture[2][64 * wall->floor_tex_y + wall->floor_tex_x];
//		ray->buf[H - y][x] = ray->texture[1][64 * wall->floor_tex_y + wall->floor_tex_x];
//		y++;
//		}
	}
}
