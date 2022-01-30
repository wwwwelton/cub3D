/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:36:18 by wleite            #+#    #+#             */
/*   Updated: 2022/01/30 00:47:50 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_data *data)
{
	if (data->state == MENU)
		draw_menu(data);
	if (data->state == GAME)
	{
		update_player(data);
		cast_all_rays(data);
		draw_game(data);
	}
	if (data->state == OPTIONS)
		draw_options(data);
	draw_fps(data);
	return (0);
}
