/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_menu_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:27:47 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/20 14:55:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keys_menu_wasd(int key, t_data *data)
{
	if (key == KEY_W && data->state == MENU)
	{
		data->menu.main++;
		if (data->menu.main > 1)
			data->menu.main = 0;
	}
	if (key == KEY_S && data->state == MENU)
	{
		data->menu.main--;
		if (data->menu.main < 0)
			data->menu.main = 1;
	}
	if (key == KEY_W && data->state == OPTIONS)
	{
		data->menu.options--;
		if (data->menu.options < 0)
			data->menu.options = 3;
	}
	if (key == KEY_S && data->state == OPTIONS)
	{
		data->menu.options++;
		if (data->menu.options > 3)
			data->menu.options = 0;
	}
}
