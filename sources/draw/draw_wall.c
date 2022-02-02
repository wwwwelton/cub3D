/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/02 12:14:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_data *data)
{
	float	dist_proj_plane;
	float	wall_height;
	int		wall_top_y;
	int		wall_bottom_y;
	float	perp_distance;
	int		pixel_color;
	int		*wall_texture_buffer;
	int		texture_offset_x;
	int		texture_offset_y;
	int		distance_from_top;
	int		texture_width;
	int		texture_height;

	for (int x = 0; x < NUM_RAYS; x++)
	{
		dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
		perp_distance = data->rays[x].distance * cos(data->rays[x].ray_angle - data->player.rot_angle);
		wall_height = (TILE_SIZE / perp_distance) * dist_proj_plane;
		wall_top_y = (WIN_HEIGHT / 2) - (wall_height / 2);
		wall_top_y = wall_top_y < 0 ? 0 : wall_top_y;
		wall_bottom_y = (WIN_HEIGHT / 2) + (wall_height / 2);
		wall_bottom_y = wall_bottom_y > WIN_HEIGHT ? WIN_HEIGHT : wall_bottom_y;
		for (int y = 0; y < wall_top_y; y++)
			data->img[FRAME].dump[(WIN_WIDTH * y) + x] = data->params.ceilcolor;
		if (data->rays[x].was_hit_vertical)
			texture_offset_x = (int)data->rays[x].wall_hit_y % TILE_SIZE;
		else
			texture_offset_x = (int)data->rays[x].wall_hit_x % TILE_SIZE;
		texture_width = data->img[3].width;
		texture_height = data->img[3].height;
		for (int y = wall_top_y; y < wall_bottom_y; y++)
		{
			distance_from_top = y + (wall_height / 2) - (WIN_HEIGHT / 2);
			texture_offset_y = distance_from_top * ((float)texture_height / wall_height);
			wall_texture_buffer = (int *)data->img[3].dump;
			pixel_color = wall_texture_buffer[(texture_width * texture_offset_y) + texture_offset_x];
			if (data->rays[x].was_hit_vertical)
				change_color_intensity(&pixel_color, 0.7);
			data->img[FRAME].dump[(WIN_WIDTH * y) + x] = pixel_color;
		}
		for (int y = wall_bottom_y; y < WIN_HEIGHT; y++)
			data->img[FRAME].dump[(WIN_WIDTH * y) + x] = data->params.floorcolor;
	}
}
