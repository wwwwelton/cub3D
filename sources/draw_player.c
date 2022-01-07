/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/07 03:21:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;

	px = data->player.px;
	py = data->player.py;
	pdx = data->player.pdx;
	pdy = data->player.pdy;
	draw_box(&data->player.img_player, px, py, 5, YELLOW);
	draw_line(&data->player.img_player, px, py, px + pdx * 5, py + pdy * 5, YELLOW);
}
