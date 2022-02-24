/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/24 03:35:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_wall_data(t_wall_data *wall, t_player player)
{
	wall->height = 0;
	wall->top_y = 0;
	wall->bottom_y = 0;
	wall->pixel_color = 0;
	wall->texture_offset_x = 0;
	wall->texture_offset_y = 0;
	wall->distance_from_top = 0;
	wall->dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall->win_height = WIN_HEIGHT + player.view_angle;
}

int	get_wall_texture(t_ray ray)
{
	if (ray.texture == 'D')
		return (TEX_DOOR);
	if (!ray.was_hit_vertical && is_ray_facing_up(ray.ray_angle)
		&& ray.texture == 'G')
		return (TEX_DOOR_SIDE);
	if (!ray.was_hit_vertical && is_ray_facing_down(ray.ray_angle)
		&& ray.texture == 'F')
		return (TEX_DOOR_SIDE);
	if (ray.was_hit_vertical && is_ray_facing_left(ray.ray_angle)
		&& ray.texture == 'Z')
		return (TEX_DOOR_SIDE);
	if (ray.was_hit_vertical && is_ray_facing_right(ray.ray_angle)
		&& ray.texture == 'Y')
		return (TEX_DOOR_SIDE);
	if (!ray.was_hit_vertical && is_ray_facing_up(ray.ray_angle))
		return (TEX_NO);
	if (!ray.was_hit_vertical && is_ray_facing_down(ray.ray_angle))
		return (TEX_SO);
	if (ray.was_hit_vertical && is_ray_facing_left(ray.ray_angle))
		return (TEX_WE);
	if (ray.was_hit_vertical && is_ray_facing_right(ray.ray_angle))
		return (TEX_EA);
	return (0);
}

int	get_wall_pixel_color(t_img texture, t_wall_data *wall)
{
	int	offset_x;
	int	offset_y;
	int	pixel_color;

	offset_x = wall->texture_offset_x;
	offset_y = wall->texture_offset_y;
	if (offset_x < 0 || offset_x > texture.width
		|| offset_y < 0 || offset_y > texture.height)
	{
		return (1);
	}
	pixel_color = texture.dump[(offset_y * texture.width) + offset_x];
	return (pixel_color);
}

void	check_inverse_offset_x(t_ray ray, int *texture_offset_x)
{
	if (!ray.was_hit_vertical && is_ray_facing_down(ray.ray_angle))
		*texture_offset_x = TILE_SIZE - *texture_offset_x;
	if (ray.was_hit_vertical && is_ray_facing_left(ray.ray_angle))
		*texture_offset_x = TILE_SIZE - *texture_offset_x;
}

int	get_texture_offset_x(t_ray ray)
{
	if (ray.was_hit_vertical)
		return ((int)ray.wall_hit_y % TILE_SIZE);
	else
		return ((int)ray.wall_hit_x % TILE_SIZE);
}
