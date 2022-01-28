/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 19:52:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_img *img, t_line line)
{
	line.dx = abs(line.x1 - line.x0);
	line.sx = line.x0 < line.x1 ? 1 : -1;
	line.dy = -abs(line.y1 - line.y0);
	line.sy = line.y0 < line.y1 ? 1 : -1;
	line.err = line.dx + line.dy;
	while (1)
	{
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		if (line.x0 < 0 || line.x0 >= WIN_WIDTH
			|| line.y0 < 0 || line.y0 >= WIN_HEIGHT)
			break ;
		my_mlx_pixel_put(img, line.x0, line.y0, line.color);
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}
