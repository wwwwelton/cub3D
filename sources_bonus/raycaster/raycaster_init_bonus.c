/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:10:51 by wleite            #+#    #+#             */
/*   Updated: 2022/02/15 00:25:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_horz_hit_data(float ray_angle,	t_hit_data *horz, t_player player)
{
	horz->hit_distance = FLT_MAX;
	horz->found_vert_wall_hit = false;
	horz->wall_hit_x = 0;
	horz->wall_hit_y = 0;
	horz->wall_texture = 0;
	horz->y_intercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_down(ray_angle))
		horz->y_intercept += TILE_SIZE;
	horz->x_intercept = player.x
		+ (horz->y_intercept - player.y) / tan(ray_angle);
	horz->y_step = TILE_SIZE;
	if (is_ray_facing_up(ray_angle))
		horz->y_step *= -1;
	horz->x_step = TILE_SIZE / tan(ray_angle);
	if (is_ray_facing_left(ray_angle) && horz->x_step > 0)
		horz->x_step *= -1;
	if (is_ray_facing_right(ray_angle) && horz->x_step < 0)
		horz->x_step *= -1;
	horz->next_touch_x = horz->x_intercept;
	horz->next_touch_y = horz->y_intercept;
}

void	init_vert_hit_data(float ray_angle,	t_hit_data *vert, t_player player)
{
	vert->hit_distance = FLT_MAX;
	vert->found_vert_wall_hit = false;
	vert->wall_hit_x = 0;
	vert->wall_hit_y = 0;
	vert->wall_texture = 0;
	vert->x_intercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(ray_angle))
		vert->x_intercept += TILE_SIZE;
	vert->y_intercept = player.y
		+ (vert->x_intercept - player.x) * tan(ray_angle);
	vert->x_step = TILE_SIZE;
	if (is_ray_facing_left(ray_angle))
		vert->x_step *= -1;
	vert->y_step = TILE_SIZE * tan(ray_angle);
	if ((is_ray_facing_up(ray_angle) && vert->y_step > 0))
		vert->y_step *= -1;
	if ((is_ray_facing_down(ray_angle) && vert->y_step < 0))
		vert->y_step *= -1;
	vert->next_touch_x = vert->x_intercept;
	vert->next_touch_y = vert->y_intercept;
}
