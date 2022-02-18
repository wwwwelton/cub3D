/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/18 19:16:40 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_visible_sprites(t_data *data)
{
	int		i;
	float	angle_sprite_player;

	data->num_visible_sprites = 0;
	i = -1;
	while (++i < data->num_sprites)
	{
		angle_sprite_player = get_angle_sprite_player(data->sprites[i], data);
		if (angle_sprite_player > PI)
			angle_sprite_player -= TWO_PI;
		if (angle_sprite_player < -PI)
			angle_sprite_player += TWO_PI;
		angle_sprite_player = fabs(angle_sprite_player);
		if (angle_sprite_player < (FOV_ANGLE / 2) + EPSILON)
		{
			data->sprites[i].visible = true;
			data->sprites[i].angle = angle_sprite_player;
			data->sprites[i].distance = get_sprite_dist(data->sprites[i], data);
			data->visible_sprites[data->num_visible_sprites] = data->sprites[i];
			data->num_visible_sprites++;
		}
		else
			data->sprites[i].visible = false;
	}
}
