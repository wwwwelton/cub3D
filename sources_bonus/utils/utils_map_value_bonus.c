/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_value_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/17 03:39:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	map_has_wall_at(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y < 0 || map_y > (map_height(data) - 1)
		|| map_x < 0 || map_x > (map_width(data) - 1))
	{
		return (false);
	}
	return (ftex_is_in_set(data->map[map_y][map_x], VALID_WALLS));
}

char	get_map_value_at(int i, int j, t_data *data)
{
	if (i < 0 || i > (map_height(data) - 1)
		|| j < 0 || j > (map_width(data) - 1))
	{
		return (0);
	}
	return (data->map[i][j]);
}

int	get_map_value_at_pos(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y < 0 || map_y > (map_height(data) - 1)
		|| map_x < 0 || map_x > (map_width(data) - 1))
	{
		return (false);
	}
	return (data->map[map_y][map_x]);
}

void	set_map_value_at_pos(float x, float y, char value, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y < 0 || map_y > (map_height(data) - 1)
		|| map_x < 0 || map_x > (map_width(data) - 1))
	{
		return ;
	}
	data->map[map_y][map_x] = value;
}
