/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_copy_layer_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:36:24 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/20 00:55:51 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	copy_layer(t_img *from, t_img *to, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < from->height && j < WIN_HEIGHT)
	{
		while (++i < from->width && i < WIN_WIDTH)
		{
			if (from->dump[i + j * from->size_l / 4] != BLACK
				&& from->dump[i + j * from->size_l / 4] != PINK)
				to->dump[x + i + ((y + j) * to->size_l / 4)]
					= from->dump[i + j * from->size_l / 4];
		}
		i = -1;
	}
}
