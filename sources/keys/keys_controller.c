/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/02 18:25:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	keys_enter(t_data *data)
{
	if (data->state == MENU && data->menu.main == 1)
		data->state = OPTIONS;
	else if (data->state == MENU && data->menu.main == 2)
		exit_game(data);
	else if (data->state == MENU && data->menu.main == 0)
	{
		data->game_running = true;
		data->state = GAME;
	}
	else if (data->state == GAME)
		data->state = MENU;
	else if (data->state == OPTIONS)
	{
		if (data->menu.options == 3)
		{
			data->menu.options = 0;
			data->state = MENU;
		}
	}
	else
		return ;
}

static void	options_menu(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		keys_menu_wasd(key, data);
	if (key == KEY_ENTER || key == KEY_N_ENTER)
		keys_enter(data);
}

static void	main_menu(int key, t_data *data)
{
	if (key == KEY_ENTER || key == KEY_N_ENTER)
		keys_enter(data);
	if (key == KEY_W || key == KEY_S)
		keys_menu_wasd(key, data);
}

static void	main_game(int key, t_data *data, int event_type)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D
		|| key == KEY_A_LEFT || key == KEY_A_RIGHT)
		keys_wasd(key, data, event_type);
	if (key == KEY_Q || key == KEY_ESC)
		exit_game(data);
	if ((key == KEY_ENTER || key == KEY_N_ENTER) && event_type == K_PRESS)
		keys_enter(data);
}

int	screen_controller(int key, t_data *data, int event_type)
{
	if (event_type == K_PRESS)
	{
		if (key == KEY_Q || key == KEY_ESC)
			exit_game(data);
		else if (data->state == GAME)
			main_game(key, data, K_PRESS);
		else if (data->state == MENU)
			main_menu(key, data);
		else if (data->state == OPTIONS)
			options_menu(key, data);
	}
	if (event_type == K_RELEASE)
	{
		if (data->state == GAME)
			main_game(key, data, K_RELEASE);
	}
	return (0);
}
