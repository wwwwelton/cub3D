/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/05 05:36:26 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_crosshair(t_data *data)
{
	int	x;
	int	y;

	x = middle_x(data->img[CROSSHAIR]);
	y = middle_y(data->img[CROSSHAIR]);
	copy_layer(&data->img[CROSSHAIR], &data->img[FRAME], x, y);
}
