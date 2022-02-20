/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/19 21:23:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	animate_guard(int index, t_sprite *sprite, t_data *data)
{
	if (sprite->frame == 0)
		sprite->texture = SPT_GUARD1;
	if (sprite->frame == 1)
		sprite->texture = SPT_GUARD2;
	if (sprite->frame == 2)
		sprite->texture = SPT_GUARD3;
	sprite->frame = (data->frame.cycle + index) % 3;
}

void	update_animations(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_sprites)
	{
		if (data->sprites[i].id == GUARD)
			animate_guard(i, &data->sprites[i], data);
	}
}
