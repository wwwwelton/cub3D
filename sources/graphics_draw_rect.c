/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_draw_rect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 20:00:29 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
