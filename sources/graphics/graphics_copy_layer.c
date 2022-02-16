/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_copy_layer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:36:24 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/16 17:20:25 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (from->dump[i + j * from->size_l / 4] != BLACK)
			to->dump[x + i + ((y + j) * to->size_l / 4)]
					= from->dump[i + j * from->size_l / 4];
		}
		i = -1;
	}
}
