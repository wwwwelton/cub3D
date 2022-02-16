/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/16 18:29:57 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render_ceil(int x, t_wall_data *wall, t_data *data)
{
	int	y;

	y = -1;
	while (++y < wall->top_y)
		pixel_put(&data->img[FRAME], x, y, data->params.ceilcolor);
}

static void	render_floor(int x, t_wall_data *wall, t_data *data)
{
	int	y;

	y = -1;
	y = wall->bottom_y - 1;
	while (++y < WIN_HEIGHT)
		pixel_put(&data->img[FRAME], x, y, data->params.floorcolor);
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
		text_num = get_wall_texture(data->rays[x]);
		wall->distance_from_top = y + (wall->height / 2) - wall->win_height / 2;
		height_scale = data->img[text_num].height / wall->height;
		wall->texture_offset_y = wall->distance_from_top * height_scale;
		wall->pixel_color = get_wall_pixel_color(data->img[text_num], wall);
		if (FOG_DIST && data->rays[x].distance > FOG_DIST)
		{
			color_factor = FOG_DIST / data->rays[x].distance;
			change_color_intensity(&wall->pixel_color, color_factor);
		}
		if (FOG_SIDE && data->rays[x].was_hit_vertical)
			change_color_intensity(&wall->pixel_color, FOG_SIDE);
		pixel_put(&data->img[FRAME], x, y, wall->pixel_color);
	}
}

void	draw_wall(t_data *data)
{
	int			x;
	t_wall_data	wall;

	init_wall_data(&wall, data->player);
	x = -1;
	while (++x < NUM_RAYS)
	{
		wall.perp_distance = get_perp_distance(data->rays[x], data);
		wall.height = (TILE_SIZE / wall.perp_distance) * wall.dist_proj_plane;
		wall.top_y = (wall.win_height / 2) - (wall.height / 2);
		if (wall.top_y < 0)
			wall.top_y = 0;
		if (wall.top_y >= WIN_HEIGHT)
			wall.top_y = WIN_HEIGHT;
		wall.bottom_y = (wall.win_height / 2) + (wall.height / 2);
		if (wall.bottom_y < 0)
			wall.bottom_y = 0;
		if (wall.bottom_y >= WIN_HEIGHT)
			wall.bottom_y = WIN_HEIGHT;
		wall.texture_offset_x = get_texture_offset_x(data->rays[x]);
		check_inverse_offset_x(data->rays[x], &wall.texture_offset_x);
		render_ceil(x, &wall, data);
		render_wall(x, &wall, data);
		render_floor(x, &wall, data);
	}
}
