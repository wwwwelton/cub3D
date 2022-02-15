/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:10:51 by wleite            #+#    #+#             */
/*   Updated: 2022/01/31 21:37:40 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_texture(t_hit_data *hit_data, t_data *data)
{
	int	ret;

	ret = get_map_value_at((int)floor(hit_data->y_to_check / TILE_SIZE),
			(int)floor(hit_data->x_to_check / TILE_SIZE), data);
	return (ret - '0');
}

float	get_hit_distance(t_hit_data *hit_data, t_data *data)
{
	float	ret;

	ret = distance_between_points(data->player.x, data->player.y,
			hit_data->wall_hit_x, hit_data->wall_hit_y);
	return (ret);
}
