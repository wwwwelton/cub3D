/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_menu_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:27:47 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/30 21:33:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	options_d(t_data *data)
{
	if (data->menu.options == 0)
		if (data->menu.opt_mouses < 3)
			data->menu.opt_mouses++;
	if (data->menu.options == 1)
		if (data->menu.opt_moves < 3)
			data->menu.opt_moves++;
	if (data->menu.options == 2)
		if (data->menu.opt_rots < 3)
			data->menu.opt_rots++;
}

void	options_a(t_data *data)
{
	if (data->menu.options == 0)
		if (data->menu.opt_mouses > 1)
			data->menu.opt_mouses--;
	if (data->menu.options == 1)
		if (data->menu.opt_moves > 1)
			data->menu.opt_moves--;
	if (data->menu.options == 2)
		if (data->menu.opt_rots > 1)
			data->menu.opt_rots--;
}

void	wasd_options(int key, t_data *data)
{
	if (key == KEY_W)
	{
		data->menu.options--;
		if (data->menu.options < 0)
			data->menu.options = 3;
	}
	if (key == KEY_S)
	{
		data->menu.options++;
		if (data->menu.options > 3)
			data->menu.options = 0;
	}
	if (key == KEY_A)
		options_a(data);
	if (key == KEY_D)
		options_d(data);
}

void	wasd_menu(int key, t_data *data)
{
	if (key == KEY_W)
	{
		data->menu.main++;
		if (data->menu.main > 1)
			data->menu.main = 0;
	}
	if (key == KEY_S)
	{
		data->menu.main--;
		if (data->menu.main < 0)
			data->menu.main = 1;
	}
}

void	keys_menu_wasd(int key, t_data *data)
{
	if (data->state == OPTIONS)
		wasd_options(key, data);
	if (data->state == MENU)
		wasd_menu(key, data);
}
