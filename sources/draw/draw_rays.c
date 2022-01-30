/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/30 00:48:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_data *data)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < NUM_RAYS)
	{
		line.x0 = data->player.x * MINIMAP_SCALE_FACTOR;
		line.y0 = data->player.y * MINIMAP_SCALE_FACTOR;
		line.x1 = data->rays[i].wall_hit_x * MINIMAP_SCALE_FACTOR;
		line.y1 = data->rays[i].wall_hit_y * MINIMAP_SCALE_FACTOR;
		line.color = RED;
		draw_line(&data->img[RAYS], line);
	}
}
