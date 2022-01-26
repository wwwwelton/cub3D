/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/26 19:55:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_fill	fillparams(int x, int y, int xlen, int ylen)
// void	fill(t_img *img, t_fill fill, int color)

static int	map_height(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

static int	map_width(char **mat)
{
	return (ft_strlen(mat[0]));
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	t_img	*img;
	t_fill	rect;

	img = &data->img[MAP];
	y = -1;
	while (++y < map_height(data->map))
	{
		x = -1;
		while (++x < map_width(data->map))
		{
			// rect = fillparams(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
			if (ftex_is_in_set(data->map[y][x], "!@"))
				fill(img, rect, WHITE);
			else
				fill(img, rect, PINK);
		}
	}
}


