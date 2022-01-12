/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/12 03:45:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
	double	px;
	double	py;

	px = data->pos_x;
	py = data->pos_y;
	draw_box(&data->player.img_player, px, py, 5, YELLOW);
	// draw_line(&data->player.img_player, px, py, px + pdx * 5, py + pdy * 5, YELLOW);
}
