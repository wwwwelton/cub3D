/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:10:51 by wleite            #+#    #+#             */
/*   Updated: 2022/01/30 00:40:01 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_horz_hit_data(float ray_angle,	t_ray_hit_data *horz_data, t_data *data)
{
	horz_data->hit_distance = FLT_MAX;
	horz_data->found_wall_hit = false;
	horz_data->wall_hit_x = 0;
	horz_data->wall_hit_y = 0;
	horz_data->wall_texture = 0;
	horz_data->y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_down(ray_angle))
		horz_data->y_intercept += TILE_SIZE;
	horz_data->x_intercept = data->player.x + (horz_data->y_intercept - data->player.y) / tan(ray_angle);
	horz_data->y_step = TILE_SIZE;
	if (is_ray_facing_up(ray_angle))
		horz_data->y_step *= -1;
	horz_data->x_step = TILE_SIZE / tan(ray_angle);
	if (is_ray_facing_left(ray_angle) && horz_data->x_step > 0)
		horz_data->x_step *= -1;
	if (is_ray_facing_right(ray_angle) && horz_data->x_step < 0)
		horz_data->x_step *= -1;
	horz_data->next_touch_x = horz_data->x_intercept;
	horz_data->next_touch_y = horz_data->y_intercept;
}

void	check_horz_hit(float ray_angle, t_ray_hit_data *horz_data, t_data *data)
{
	init_horz_hit_data(ray_angle, horz_data, data);
	while (is_inside_map(horz_data->next_touch_x, horz_data->next_touch_y, data))
	{
		horz_data->x_to_check = horz_data->next_touch_x;
		horz_data->y_to_check = horz_data->next_touch_y;
		if (is_ray_facing_up(ray_angle))
			horz_data->y_to_check -= 1;
		if (map_has_wall_at(horz_data->x_to_check, horz_data->y_to_check, data))
		{
			horz_data->wall_hit_x = horz_data->next_touch_x;
			horz_data->wall_hit_y = horz_data->next_touch_y;
			horz_data->wall_texture = get_map_at((int)floor(horz_data->y_to_check / TILE_SIZE), (int)floor(horz_data->x_to_check / TILE_SIZE), data);
			horz_data->found_wall_hit = true;
			horz_data->hit_distance = distance_between_points(data->player.x, data->player.y, horz_data->wall_hit_x, horz_data->wall_hit_y);
			break ;
		}
		else
		{
			horz_data->next_touch_x += horz_data->x_step;
			horz_data->next_touch_y += horz_data->y_step;
		}
	}
}

void	init_vert_hit_data(float ray_angle,	t_ray_hit_data *vert_data, t_data *data)
{
	vert_data->hit_distance = FLT_MAX;
	vert_data->found_wall_hit = false;
	vert_data->wall_hit_x = 0;
	vert_data->wall_hit_y = 0;
	vert_data->wall_texture = 0;
	vert_data->x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(ray_angle))
		vert_data->x_intercept += TILE_SIZE;
	vert_data->y_intercept = data->player.y + (vert_data->x_intercept - data->player.x) * tan(ray_angle);
	vert_data->x_step = TILE_SIZE;
	if (is_ray_facing_left(ray_angle))
		vert_data->x_step *= -1;
	vert_data->y_step = TILE_SIZE * tan(ray_angle);
	if ((is_ray_facing_up(ray_angle) && vert_data->y_step > 0))
		vert_data->y_step *= -1;
	if ((is_ray_facing_down(ray_angle) && vert_data->y_step < 0))
		vert_data->y_step *= -1;
	vert_data->next_touch_x = vert_data->x_intercept;
	vert_data->next_touch_y = vert_data->y_intercept;
}

void	check_vert_hit(float ray_angle, t_ray_hit_data *vert_data, t_data *data)
{
	init_vert_hit_data(ray_angle, vert_data, data);
	while (is_inside_map(vert_data->next_touch_x, vert_data->next_touch_y, data))
	{
		vert_data->x_to_check = vert_data->next_touch_x;
		vert_data->y_to_check = vert_data->next_touch_y;
		if (is_ray_facing_left(ray_angle))
			vert_data->x_to_check -= 1;
		if (map_has_wall_at(vert_data->x_to_check, vert_data->y_to_check, data))
		{
			vert_data->wall_hit_x = vert_data->next_touch_x;
			vert_data->wall_hit_y = vert_data->next_touch_y;
			vert_data->wall_texture = get_map_at((int)floor(vert_data->y_to_check / TILE_SIZE), (int)floor(vert_data->x_to_check / TILE_SIZE), data);
			vert_data->found_wall_hit = true;
			vert_data->hit_distance = distance_between_points(data->player.x, data->player.y, vert_data->wall_hit_x, vert_data->wall_hit_y);
			break ;
		}
		else
		{
			vert_data->next_touch_x += vert_data->x_step;
			vert_data->next_touch_y += vert_data->y_step;
		}
	}
}

void	cast_ray(float ray_angle, int col_id, t_data *data)
{
	t_ray_hit_data	horz_data;
	t_ray_hit_data	vert_data;

	check_horz_hit(ray_angle, &horz_data, data);
	check_vert_hit(ray_angle, &vert_data, data);
	if (vert_data.hit_distance < horz_data.hit_distance)
	{
		data->rays[col_id].distance = vert_data.hit_distance;
		data->rays[col_id].wall_hit_x = vert_data.wall_hit_x;
		data->rays[col_id].wall_hit_y = vert_data.wall_hit_y;
		data->rays[col_id].texture = vert_data.wall_texture;
		data->rays[col_id].was_hit_vertical = true;
		data->rays[col_id].ray_angle = ray_angle;
	}
	else
	{
		data->rays[col_id].distance = horz_data.hit_distance;
		data->rays[col_id].wall_hit_x = horz_data.wall_hit_x;
		data->rays[col_id].wall_hit_y = horz_data.wall_hit_y;
		data->rays[col_id].texture = horz_data.wall_texture;
		data->rays[col_id].was_hit_vertical = false;
		data->rays[col_id].ray_angle = ray_angle;
	}
}

void	cast_all_rays(t_data *data)
{
	float	fov_angle;
	float	dist_proj_plane;
	float	ray_angle;
	float	player_rot_angle;
	int		col;

	fov_angle = (60 * (PI / 180));
	dist_proj_plane = (WIN_WIDTH / 2) / tan(fov_angle / 2);
	player_rot_angle = data->player.rot_angle;
	col = -1;
	while (++col < NUM_RAYS)
	{
		ray_angle = player_rot_angle + atan((col - NUM_RAYS / 2) / dist_proj_plane);
		normalize_angle(&ray_angle);
		cast_ray(ray_angle, col, data);
	}
}

void	render_map_rays(t_data *data)
{
	t_line	line;

	for (int i = 0; i < NUM_RAYS; i++)
	{
		line.x0 = data->player.x * MINIMAP_SCALE_FACTOR;
		line.y0 = data->player.y * MINIMAP_SCALE_FACTOR;
		line.x1 = data->rays[i].wall_hit_x * MINIMAP_SCALE_FACTOR;
		line.y1 = data->rays[i].wall_hit_y * MINIMAP_SCALE_FACTOR;
		line.color = RED;
		draw_line(&data->img[PLAYER], line);
	}
}
