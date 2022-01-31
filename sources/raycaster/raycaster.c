/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:10:51 by wleite            #+#    #+#             */
/*   Updated: 2022/01/31 16:16:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_horz_hit(float ray_angle, t_hit_data *horz, t_data *data)
{
	init_horz_hit_data(ray_angle, horz, data->player);
	while (is_inside_map(horz->next_touch_x, horz->next_touch_y, data))
	{
		horz->x_to_check = horz->next_touch_x;
		horz->y_to_check = horz->next_touch_y;
		if (is_ray_facing_up(ray_angle))
			horz->y_to_check -= 1;
		if (map_has_wall_at(horz->x_to_check, horz->y_to_check, data))
		{
			horz->wall_hit_x = horz->next_touch_x;
			horz->wall_hit_y = horz->next_touch_y;
			horz->wall_texture = get_map_texture(horz, data);
			horz->found_vert_wall_hit = false;
			horz->hit_distance = get_hit_distance(horz, data);
			break ;
		}
		else
		{
			horz->next_touch_x += horz->x_step;
			horz->next_touch_y += horz->y_step;
		}
	}
}

void	check_vert_hit(float ray_angle, t_hit_data *vert, t_data *data)
{
	init_vert_hit_data(ray_angle, vert, data->player);
	while (is_inside_map(vert->next_touch_x, vert->next_touch_y, data))
	{
		vert->x_to_check = vert->next_touch_x;
		vert->y_to_check = vert->next_touch_y;
		if (is_ray_facing_left(ray_angle))
			vert->x_to_check -= 1;
		if (map_has_wall_at(vert->x_to_check, vert->y_to_check, data))
		{
			vert->wall_hit_x = vert->next_touch_x;
			vert->wall_hit_y = vert->next_touch_y;
			vert->wall_texture = get_map_texture(vert, data);
			vert->found_vert_wall_hit = true;
			vert->hit_distance = get_hit_distance(vert, data);
			break ;
		}
		else
		{
			vert->next_touch_x += vert->x_step;
			vert->next_touch_y += vert->y_step;
		}
	}
}

void	cast_ray(float ray_angle, int col_id, t_data *data)
{
	t_hit_data	horz;
	t_hit_data	vert;

	check_horz_hit(ray_angle, &horz, data);
	check_vert_hit(ray_angle, &vert, data);
	if (vert.hit_distance < horz.hit_distance)
	{
		data->rays[col_id].distance = vert.hit_distance;
		data->rays[col_id].wall_hit_x = vert.wall_hit_x;
		data->rays[col_id].wall_hit_y = vert.wall_hit_y;
		data->rays[col_id].texture = vert.wall_texture;
		data->rays[col_id].was_hit_vertical = true;
		data->rays[col_id].ray_angle = ray_angle;
	}
	else
	{
		data->rays[col_id].distance = horz.hit_distance;
		data->rays[col_id].wall_hit_x = horz.wall_hit_x;
		data->rays[col_id].wall_hit_y = horz.wall_hit_y;
		data->rays[col_id].texture = horz.wall_texture;
		data->rays[col_id].was_hit_vertical = false;
		data->rays[col_id].ray_angle = ray_angle;
	}
}

void	cast_all_rays(t_data *data)
{
	float	fov_angle;
	float	dist_proj_plane;
	float	ray_angle;
	float	p_rot_angle;
	int		col;

	fov_angle = (60 * (PI / 180));
	dist_proj_plane = (WIN_WIDTH / 2) / tan(fov_angle / 2);
	p_rot_angle = data->player.rot_angle;
	col = -1;
	while (++col < NUM_RAYS)
	{
		ray_angle = p_rot_angle + atan((col - NUM_RAYS / 2) / dist_proj_plane);
		normalize_angle(&ray_angle);
		cast_ray(ray_angle, col, data);
	}
}
