/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/14 15:03:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define mapWidth 24
# define mapHeight 24

int	worldMap[mapWidth][mapHeight] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	draw_rays(t_data *data)
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		x;
	int		y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;

	double	wall_x;
	double	step;
	double	texture_pos;

	int	texture_x;
	int	texture_y;

	//FLOOR / CEIL
	float	ray_dir_x0;
	float	ray_diry0;
	float	ray_dir_x1;
	float	ray_diry1;
	int	p;
	float	pos_z;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_Y;
	float	floor_x;
	float	floor_y;
	int		cell_c;
	int		cell_y;
	//FLOOR / CEIL

	t_player	*player;
	t_ray		*ray;

	ray = &data->ray;
	player = &data->player;

	//FLOOR CASTING
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		ray_dir_x0 = data->ray.dir_x - data->ray.plane_x;
		ray_diry0 = data->ray.dir_y - data->ray.plane_y;
		ray_dir_x1 = data->ray.dir_x + data->ray.plane_x;
		ray_diry1 = data->ray.dir_y + data->ray.plane_y;
		p = y - WIN_HEIGHT / 2;
		pos_z = 0.5 * WIN_HEIGHT;
		row_distance = pos_z / p;
		floor_step_x = row_distance * (ray_dir_x1 - ray_dir_x0) / WIN_WIDTH;
		floor_step_Y = row_distance * (ray_diry1 - ray_diry0) / WIN_WIDTH;
		floor_x = data->player.pos_x + row_distance * ray_dir_x0;
		floor_y = data->player.pos_y + row_distance * ray_diry0;

		for (int x = 0; x < WIN_WIDTH; ++x)
		{
			cell_c = (int)(floor_x);
			cell_y = (int)(floor_y);
			texture_x = (int)(TEX_WIDTH * (floor_x - cell_c)) & (TEX_WIDTH - 1);
			texture_y = (int)(TEX_HEIGHT * (floor_y - cell_y)) & (TEX_HEIGHT - 1);
			floor_x += floor_step_x;
			floor_y += floor_step_Y;
			color = get_pixel_color(&data->img[TEX_WE], texture_x, texture_y, TEX_WIDTH, TEX_HEIGHT);
			my_mlx_pixel_put(&data->img[RAYS], x, y, color);
			color = get_pixel_color(&data->img[TEX_EA], texture_x, texture_y, TEX_WIDTH, TEX_HEIGHT);
			my_mlx_pixel_put(&data->img[RAYS], x, WIN_HEIGHT - y - 1, color);
		}
	}
	//FLOOR CASTING

	//WALL CASTING
	x = -1;
	while (++x < WIN_WIDTH)
	{
		cam_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = ray->dir_x + ray->plane_x * cam_x;
		ray_dir_y = ray->dir_y + ray->plane_y * cam_x;
		map_x = (int)player->pos_x;
		map_y = (int)player->pos_y;
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (player->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - player->pos_x) * delta_dist_x;
		}

		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (player->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - player->pos_y) * delta_dist_y;
		}

		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (worldMap[map_x][map_y] > 0)
				hit = 1;
		}
		if (side == 0)
			wall_dist = (map_x - player->pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			wall_dist = (map_y - player->pos_y + (1 - step_y) / 2) / ray_dir_y;

		line_height = (int)(WIN_HEIGHT / wall_dist);
		draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if(draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WIN_HEIGHT / 2;
		if(draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;

		if (side == 0)
			wall_x = player->pos_y + wall_dist * ray_dir_y;
		else
			wall_x = player->pos_x + wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);

		texture_x = (int)(wall_x * (double)TEX_WIDTH);
		if (side == 0 && ray_dir_x > 0)
			texture_x = TEX_WIDTH - texture_x - 1;
		if (side == 1 && ray_dir_y < 0)
			texture_x = TEX_WIDTH - texture_x - 1;

		step = 1.0 * TEX_HEIGHT / line_height;
		texture_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;

		for (int y = draw_start; y < draw_end; y++)
		{
			texture_y = (int)texture_pos & (TEX_HEIGHT - 1);
			texture_pos += step;
			if (side == 1 && ray_dir_y < 0)
				// color = get_pixel_color(&data->img[TEX_NO], texture_x, texture_y, TEX_WIDTH, TEX_HEIGHT);
				color = PINK;
			else if (side == 1 && ray_dir_y >= 0)
				color = BLUE;
			else if (side == 0 && ray_dir_x < 0)
				// color = get_pixel_color(&data->img[TEX_SO], texture_x, texture_y, TEX_WIDTH, TEX_HEIGHT);
				color = RED;
			else if (side == 0 && ray_dir_x >= 0)
				color = YELLOW;
			// if (side == 1)
			// 	color = (color >> 1) & 0x7F7F7F;
			my_mlx_pixel_put(&data->img[RAYS], x, y, color);
		}
		// printf("wall_x: %f\n", wall_x);
		// printf("side_dist_x: %f\n", side_dist_x);
		// printf("side_dist_y: %f\n", side_dist_y);
		// printf("ray_dir_x: %f\n", ray_dir_x);
		// printf("ray_dir_y: %f\n", ray_dir_y);
		// printf("pos_x: %f\n", data->player.pos_x);
		// printf("pos_y: %f\n", data->player.pos_y);
		// printf("\n");
		// printf("\e[1;1H\e[2J");
	}
	//WALL CASTING
}
