/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/17 03:12:01 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	map_height(t_data *data)
{
	static int	map_height = -1;

	if (map_height == -1)
	{
		map_height = 0;
		while (data->map[map_height])
			map_height++;
	}
	return (map_height);
}

int	map_width(t_data *data)
{
	static int	map_width = -1;

	if (map_width == -1)
		map_width = ft_strlen(data->map[0]);
	return (map_width);
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
