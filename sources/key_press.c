/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 01:11:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_W)
		data->player.py -= 10;
	if (key == KEY_S)
		data->player.py += 10;
	if (key == KEY_A)
		data->player.px -= 10;
	if (key == KEY_D)
		data->player.px += 10;
	draw_screen(data);
	return (0);
}
