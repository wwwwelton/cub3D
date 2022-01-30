/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/29 23:26:11 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_wall_at(t_data *data, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	return (ftex_is_in_set(data->map[map_y][map_x], "!@"));
}

int	map_height(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	map_width(char **mat)
{
	return (ft_strlen(mat[0]));
}

int	is_inside_map(float x, float y, t_data *data)
{
	if (x >= 0 && x <= map_width(data->map) * TILE_SIZE
		&& y >= 0 && y <= map_height(data->map) * TILE_SIZE)
			return (true);
	return (false);
}

int get_map_at(int i, int j, t_data *data)
{
	return (data->map[i][j] - '0');
}
