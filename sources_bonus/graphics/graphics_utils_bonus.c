/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/24 03:22:29 by wleite           ###   ########.fr       */
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

t_img	*resize_image(t_img *image_to_scale, float scale, t_data *data)
{
	int		count_w;
	int		count_h;
	int		img_width;
	int		img_height;
	t_img	*result;

	img_width = image_to_scale->width * scale;
	img_height = image_to_scale->height * scale;
	result = malloc(sizeof(t_img));
	init_img(data, result, img_width, img_height);
	count_h = -1;
	while (++count_h <= img_height)
	{
		count_w = -1;
		while (++count_w <= img_width)
		{
			result->dump[(count_h * img_width) + count_w]
				= image_to_scale->dump[((int)(count_h / scale)
					*image_to_scale->width) + (int)(count_w / scale)];
		}
	}
	return (result);
}
