/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/27 19:31:55 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
	t_img		*img;
	t_player	player;
	t_rect		rect;
	t_line		line;

	rect.width = TILE_SIZE * MINIMAP_SCALE_FACTOR;
	rect.height = TILE_SIZE * MINIMAP_SCALE_FACTOR;
	img = &data->img[MAP];
	player = data->player;
	rect.x = player.x * MINIMAP_SCALE_FACTOR;
	rect.y = player.y * MINIMAP_SCALE_FACTOR;
	rect.width = player.width * MINIMAP_SCALE_FACTOR;
	rect.height = player.height * MINIMAP_SCALE_FACTOR;
	rect.color = YELLOW;
	line.x0 = rect.x;
	line.y0 = rect.y;
	line.x1 = rect.x + cos(player.rot_angle) * (150 * MINIMAP_SCALE_FACTOR);
	line.y1 = rect.y + sin(player.rot_angle) * (150 * MINIMAP_SCALE_FACTOR);
	line.color = RED;
	draw_rect(img, rect);
	draw_line(img, line);
}
