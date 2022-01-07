/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/07 03:27:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vert_line(t_img *img, int x0, int y0, int y1, int thick, int color)
{
	int	i;

	while (y0 <= y1)
	{
		i = 0;
		while (i < thick)
		{
			my_mlx_pixel_put(img, x0 + i, y0, color);
			i++;
		}
		y0++;
	}
}

void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx =  abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		if (x0 == x1 && y0 == y1)
			break ;
		my_mlx_pixel_put(img, x0, y0, color);
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
