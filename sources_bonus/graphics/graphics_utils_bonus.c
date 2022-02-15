/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/15 00:25:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	change_color_intensity(int *color, float factor)
{
	int	r;
	int	g;
	int	b;

	r = (*color & 0xFF0000) * factor;
	g = (*color & 0x00FF00) * factor;
	b = (*color & 0x0000FF) * factor;
	*color = (r & 0xFF0000) | (g & 0x00FF00) | (b & 0x0000FF);
}

int	blend_colors(int color1, int color2, float alpha1, float alpha2)
{
	change_color_intensity(&color1, alpha1);
	change_color_intensity(&color2, alpha2);
	return (color1 + color2);
}
