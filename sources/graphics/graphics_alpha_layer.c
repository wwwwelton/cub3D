/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_alpha_layer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:37:35 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/05 10:38:51 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_xy	layer_vars(int x, int y)
{
	t_xy	xy;

	xy.x = x;
	xy.y = y;
	return (xy);
}

void	alpha_layer(t_img *from, t_img *to, t_xy xy, float alpha)
{
	int	i;
	int	j;
	int	*rgb_from;
	int	*rgb_to;

	i = -1;
	j = -1;
	while (++j < from->height)
	{
		while (++i < from->width)
		{
			rgb_from = &from->dump[i + j * from->size_l / 4];
			rgb_to = &to->dump[xy.x + i + ((xy.y + j) * to->size_l / 4)];
			if (*rgb_from != BLACK)
				*rgb_to = blend_colors(*rgb_from, *rgb_to, alpha, 1 - alpha);
		}
		i = -1;
	}
}
