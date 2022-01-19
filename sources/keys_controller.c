/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/19 10:14:15 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keys_enter(t_data *data)
{
	data->state = GAME;
}

void	main_menu(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == KEY_ENTER)
		keys_enter(data);
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
	if (data->state == GAME)
		main_game(key, data);
	if (data->state == MENU)
		main_menu(key, data);
	return (0);
}

