/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/05 02:45:12 by jofelipe         ###   ########.fr       */
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

void	pixel_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	img->dump[(y * img->width) + x] = color;
}

int	alpha_blending2(int color, float factor)
{
	int	r;
	int	g;
	int	b;

	r = (color & 0xFF0000) * factor;
	g = (color & 0x00FF00) * factor;
	b = (color & 0x0000FF) * factor;
	return ((r & 0xFF0000) | (g & 0x00FF00) | (b & 0x0000FF));
}

void	alpha_blending(int *color, float factor)
{
	int	r;
	int	g;
	int	b;

	r = (*color & 0xFF0000) * factor;
	g = (*color & 0x00FF00) * factor;
	b = (*color & 0x0000FF) * factor;
	*color = (r & 0xFF0000) | (g & 0x00FF00) | (b & 0x0000FF);
}
