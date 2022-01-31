/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/31 16:25:42 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

int	map_width(t_data *data)
{
	return (ft_strlen(data->map[0]));
}

int	map_has_wall_at(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	return (ftex_is_in_set(data->map[map_y][map_x], "!@"));
}

int	is_inside_map(float x, float y, t_data *data)
{
	if (x >= 0 && x <= map_width(data) * TILE_SIZE
		&& y >= 0 && y <= map_height(data) * TILE_SIZE)
	{
		return (true);
	}
	return (false);
}

int	get_map_value(int i, int j, t_data *data)
{
	if (i < 0 || i > map_height(data)
		|| j < 0 || j > map_width(data))
	{
		return (-1);
	}
	return (data->map[i][j] - '0');
}
