/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/27 18:00:22 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_door_side(t_ray ray)
{
	if (!ray.was_hit_vertical && is_ray_facing_up(ray.ray_angle)
		&& ray.texture == 'G')
		return (true);
	if (!ray.was_hit_vertical && is_ray_facing_down(ray.ray_angle)
		&& ray.texture == 'F')
		return (true);
	if (ray.was_hit_vertical && is_ray_facing_left(ray.ray_angle)
		&& ray.texture == 'Z')
		return (true);
	if (ray.was_hit_vertical && is_ray_facing_right(ray.ray_angle)
		&& ray.texture == 'Y')
		return (true);
	return (false);
}

int	get_wall_texture(t_ray ray)
{
	if (ray.texture == DOOR)
		return (TEX_DOOR);
	if (is_door_side(ray))
		return (TEX_DOOR_SIDE);
	if (ray.texture == BBLOCK)
		return (TEX_BBLOCK);
	if (ray.texture == RBLOCK)
		return (TEX_RBLOCK);
	if (ray.texture == PBLOCK)
		return (TEX_PBLOCK);
	if (ray.texture == JBLOCK)
		return (TEX_JBLOCK);
	if (ray.texture == WBLOCK)
		return (TEX_WBLOCK);
	if (ray.texture == TBLOCK)
		return (TEX_TBLOCK);
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
