/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/02 17:54:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_ceil(int x, t_wall_data *wall, t_data *data)
{
	int	y;

	y = -1;
	while (++y < wall->top_y)
		data->img[FRAME].dump[(WIN_WIDTH * y) + x] = data->params.ceilcolor;
}

static void	render_floor(int x, t_wall_data *wall, t_data *data)
{
	int	y;

	y = -1;
	y = wall->bottom_y - 1;
	while (++y < WIN_HEIGHT)
		data->img[FRAME].dump[(WIN_WIDTH * y) + x] = data->params.floorcolor;
}

static void	render_wall(int x, t_wall_data *wall, t_data *data)
{
	int		y;
	int		text_num;
	float	height_scale;
	float	color_factor;

	y = wall->top_y - 1;
	while (++y < wall->bottom_y)
	{
		text_num = get_wall_texture_side(data->rays[x]);
		wall->distance_from_top = y + (wall->height / 2) - (WIN_HEIGHT / 2);
		height_scale = data->img[text_num].height / wall->height;
		wall->texture_offset_y = wall->distance_from_top * height_scale;
		wall->pixel_color = get_wall_pixel_color(data->img[text_num], wall);
		if (data->rays[x].distance > FOG_DIST)
		{
			color_factor = FOG_DIST / data->rays[x].distance;
			change_color_intensity(&wall->pixel_color, color_factor);
		}
		if (data->rays[x].was_hit_vertical)
			change_color_intensity(&wall->pixel_color, 0.7);
		data->img[FRAME].dump[(WIN_WIDTH * y) + x] = wall->pixel_color;
	}
}

void	draw_wall(t_data *data)
{
	int			x;
	t_wall_data	wall;

	init_wall_data(&wall);
	x = -1;
	while (++x < NUM_RAYS)
	{
		wall.perp_distance = get_perp_distance(data->rays[x], data);
		wall.height = (TILE_SIZE / wall.perp_distance) * wall.dist_proj_plane;
		wall.top_y = (WIN_HEIGHT / 2) - (wall.height / 2);
		if (wall.top_y < 0)
			wall.top_y = 0;
		wall.bottom_y = (WIN_HEIGHT / 2) + (wall.height / 2);
		if (wall.bottom_y > WIN_HEIGHT)
			wall.bottom_y = WIN_HEIGHT;
		if (data->rays[x].was_hit_vertical)
			wall.texture_offset_x = (int)data->rays[x].wall_hit_y % TILE_SIZE;
		else
			wall.texture_offset_x = (int)data->rays[x].wall_hit_x % TILE_SIZE;
		check_inverse_offset_x(data->rays[x], &wall);
		render_ceil(x, &wall, data);
		render_wall(x, &wall, data);
		render_floor(x, &wall, data);
	}
}
