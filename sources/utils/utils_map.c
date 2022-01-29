/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/27 13:06:41 by wleite           ###   ########.fr       */
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
