/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/07 03:21:08 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	int		mapX = 8, mapY = 8;
	int		map[64] =
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 0, 0, 1, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	int		x;
	int		y;

	y = -1;
	while (++y < mapY)
	{
		x = -1;
		while (++x < mapX)
		{
			if (map[y * mapX + x] == 1)
				draw_box(&data->img_map, x * 64, y * 64, 64, WHITE);
			else
				draw_box(&data->img_map, x * 64, y * 64, 64, BLACKB);
			draw_line(&data->img_map, x * 64, 0, x * 64, IMG_HEIGHT, GRAY);
			draw_line(&data->img_map, 0, y * 64, IMG_WIDTH, y * 64, GRAY);
		}
	}
}
