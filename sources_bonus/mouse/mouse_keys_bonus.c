/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keys_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:26 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/21 22:06:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_key_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->player.action_shoot = true;
	return (0);
}

int	mouse_key_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->player.action_shoot = false;
	return (0);
}
