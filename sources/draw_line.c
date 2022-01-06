/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/06 01:14:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_data *data, t_img *img, int x0, int y0, int x1, int y1)
{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	center = 0;

	if (&data->img_pixel1 == img)
		center = 4;
	if (&data->img_pixel2 == img || &data->img_pixel3 == img)
		center = 4;
	dx =  abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		if (x0 == x1 && y0 == y1)
			break ;
		draw_box(data, img, x0 + center, y0 + center);
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
