/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 19:48:49 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	rgb += (r & 0xFF) << 16;
	rgb += (g & 0XFF) << 8;
	rgb += (b & 0XFF);
	return (rgb);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > IMG_WIDTH || y < 0 || y > IMG_HEIGHT)
		return ;
	dst = (char *)img->dump + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	fill_color(t_img *img, int color)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
			img->dump[count_h * IMG_WIDTH + count_w] = color;
	}
}

void	_copy_layer(t_img *from, t_img *to, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < from->height)
	{
		while (++i < from->width)
		{
			if (from->dump[i + j * from->size_l / 4] != BLACK)
			to->dump[x + i + ((y + j) * to->size_l / 4)]
					= from->dump[i + j * from->size_l / 4];
		}
		i = -1;
	}
}

void	copy_layer(t_img *img_src, t_img *img_dst, int color)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (img_dst->dump[count_h * IMG_WIDTH + count_w] == color)
				img_dst->dump[count_h * IMG_WIDTH + count_w]
					= img_src->dump[count_h * IMG_WIDTH + count_w];
		}
	}
}

void	draw_rect(t_img *img, t_rect rect)
{
	int		x;
	int		y;

	rect.height += rect.y;
	rect.width += rect.x;
	y = rect.y - 1;
	while (++y < rect.height)
	{
		x = rect.x - 1;
		while (++x < rect.width)
		{
			if (y < 0 || y >= WIN_HEIGHT || x < 0 || x >= WIN_WIDTH)
				return ;
			img->dump[y * IMG_WIDTH + x] = rect.color;
		}
	}
}

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
