/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/13 20:44:50 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define mapWidth 24
# define mapHeight 24

int	worldMap[mapWidth][mapHeight] =
{
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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

	t_player	*player;
	t_ray		*ray;

	ray = &data->ray;
	player = &data->player;
	x = 0;
	while (x < WIN_WIDTH)
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
			if (worldMap[map_x][map_y] == 9)
				color = get_pixel_color(&data->img[TEX_NO], texture_x, texture_y, TEX_WIDTH, TEX_HEIGHT);
			else
				color = get_pixel_color(&data->img[TEX_SO], texture_x, texture_y, TEX_WIDTH, TEX_HEIGHT);
			if (side == 1)
				color = (color >> 1) & 0x7F7F7F;
			my_mlx_pixel_put(&data->img[RAYS], x, y, color);
		}
		x++;
	}
}
