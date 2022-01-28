/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:36:18 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 19:37:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(t_data *data)
{
	if (data->state == MENU)
		draw_menu(data);
	if (data->state == GAME)
	{
		update_player(data);
		draw_screen(data);
	}
	if (data->state == OPTIONS)
		draw_options(data);
	return (0);
}
