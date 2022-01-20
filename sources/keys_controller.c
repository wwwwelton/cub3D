/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/20 14:49:24 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keys_enter(t_data *data)
{
	if (data->state == MENU)
		if (data->menu.main == 1)
			data->state = OPTIONS;
	if (data->state == MENU)
		if (data->menu.main == 0)
			data->state = GAME;
	if (data->state == OPTIONS)
		if (data->menu.options == 4)
		{
			data->menu.options = 0;
			data->state = MENU;
		}
}

void	options_menu(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		keys_menu_wasd(key, data);
}

void	main_menu(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == KEY_ENTER)
		keys_enter(data);
	if (key == KEY_W || key == KEY_S)
		keys_menu_wasd(key, data);
}

void	main_game(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		keys_wasd(key, data);
	if (key == KEY_Q || key == KEY_ESC)
		exit_game(data);
}

int	screen_controller(int key, t_data *data)
{
	if (key == KEY_Q || key == KEY_ESC)
		exit_game(data);
	if (data->state == GAME)
		main_game(key, data);
	if (data->state == MENU)
		main_menu(key, data);
	if (data->state == OPTIONS)
		options_menu(key, data);
	return (0);
}

