/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 19:54:29 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
