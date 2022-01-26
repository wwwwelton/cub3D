/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:26 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/26 17:20:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(t_data *data)
{
	(void)data;
}
void	key_a(t_data *data)
{
	(void)data;
}

void	key_s(t_data *data)
{
	(void)data;
}

void	key_d(t_data *data)
{
	(void)data;
}

void	keys_wasd(int key, t_data *data)
{
	if (key == KEY_W)
		key_w(data);
	if (key == KEY_A)
		key_a(data);
	if (key == KEY_S)
		key_s(data);
	if (key == KEY_D)
		key_d(data);
}
