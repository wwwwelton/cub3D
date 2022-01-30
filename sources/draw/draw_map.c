/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/29 23:15:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	t_img	*img;
	t_rect	rect;

	rect.width = TILE_SIZE * MINIMAP_SCALE_FACTOR;
	rect.height = TILE_SIZE * MINIMAP_SCALE_FACTOR;
	img = &data->img[MAP];
	y = -1;
	while (++y < map_height(data->map))
	{
		x = -1;
		while (++x < map_width(data->map))
		{
			rect.x = x * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			rect.y = y * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			if (ftex_is_in_set(data->map[y][x], "!@"))
				rect.color = WHITE;
			else if (ftex_is_in_set(data->map[y][x], "0N"))
				rect.color = BLACKB;
			else
				continue ;
			draw_rect(img, rect);
		}
	}
}
