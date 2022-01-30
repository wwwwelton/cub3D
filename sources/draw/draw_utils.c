/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/30 18:53:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_menu_item(t_data *data, int src, int offy, int offx)
{
	t_menuelem	elem;

	elem.dst = &data->img[SCREEN];
	elem.src = &data->img[src];
	elem.x = middle_x(data->img[src]) - offy;
	elem.y = middle_y(data->img[src]) + offx;
	copy_layer(elem.src, elem.dst, elem.x, elem.y);
}

int	middle_x(t_img img)
{
	return (IMG_WIDTH / 2 - (img.width / 2));
}

int	middle_y(t_img img)
{
	return (IMG_HEIGHT / 2 - (img.height / 2));
}

void	copy_layer(t_img *from, t_img *to, int x, int y)
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
