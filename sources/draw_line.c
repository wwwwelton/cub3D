/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 05:55:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int line_length, int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	p;
// 	int	x;
// 	int	y;

// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	x = x0;
// 	y = y0;
// 	p = 2 * dy - dx;
// 	while (x < x1)
// 	{
// 		if (p >= 0)
// 		{
// 			// mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win, x, y, color);
// 			my_mlx_pixel_put(data, x, y, line_length, color);
// 			y = y + 1;
// 			p = p + (2 * (dy - dx));
// 		}
// 		else
// 		{
// 			// mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win, x, y, color);
// 			my_mlx_pixel_put(data, x, y, line_length, color);
// 			p = p + 2 * dy;
// 		}
// 		x = x + 1;
// 	}
// }

float	abst(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

// void	draw_line_low(t_data *data, int x0, int y0, int x1, int y1, int line_length, int color)
// {
// 	float	dx;
// 	float	dy;
// 	float	x;
// 	float	y;
// 	float	yi;
// 	float	p;

// 	yi = 1;
// 	x = x1;
// 	y = y1;
// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy = -dy;
// 	}
// 	p = (2 * dy) - dx;
// 	while (x <= x1)
// 	{
// 		my_mlx_pixel_put(data, x, y, line_length, color);
// 		if (p > 0)
// 		{
// 			y = y + yi;
// 			p = p + (2 * (dy - dx));
// 		}
// 		else
// 			p = p + 2 * dy;
// 		x++;
// 	}
// }

// void	draw_line_high(t_data *data, int x0, int y0, int x1, int y1, int line_length, int color)
// {
// 	float	dx;
// 	float	dy;
// 	float	x;
// 	float	y;
// 	float	xi;
// 	float	p;

// 	xi = 1;
// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	x = x1;
// 	y = y1;
// 	if (dx < 0)
// 	{
// 		xi = -1;
// 		dx = -dx;
// 	}
// 	p = (2 * dx) - dy;
// 	while (y <= y1)
// 	{
// 		my_mlx_pixel_put(data, x, y, line_length, color);
// 		if (p > 0)
// 		{
// 			x = x + xi;
// 			p = p + (2 * (dx - dy));
// 		}
// 		else
// 			p = p + 2 * dx;
// 		y++;
// 	}
// }

// void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int line_length, int color)
// {
// 	draw_line_low(data, x0, y0, x1, y1, line_length, color);
// }

void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int line_length, int color)
{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx =  abst(x1-x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abst(y1-y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx+dy;
	while (1)
	{
		my_mlx_pixel_put(data, x0, y0, line_length, color);
		if (x0 == x1 && y0 == y1)
			break ;
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
