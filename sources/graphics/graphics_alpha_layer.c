/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_alpha_layer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:37:35 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/05 05:37:51 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	alpha_layer(t_img *from, t_img *to, int x, int y)
{
	int	i;
	int	j;
	int	*color_from;
	int	*color_to;

	i = -1;
	j = -1;
	while (++j < from->height)
	{
		while (++i < from->width)
		{
			color_from = &from->dump[i + j * from->size_l / 4];
			color_to = &to->dump[x + i + ((y + j) * to->size_l / 4)];
			if (*color_from != BLACK)
				*color_to = blend_colors(*color_from, *color_to, 0.7, 0.3);
		}
		i = -1;
	}
}
