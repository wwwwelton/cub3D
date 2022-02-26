/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/26 19:47:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_sprite_texture(int id)
{
	if (id == ARMOR)
		return (SPT_ARMOR);
	if (id == BARREL)
		return (SPT_BARREL);
	if (id == DRUM)
		return (SPT_DRUM);
	if (id == MINITREE)
		return (SPT_MINITREE);
	if (id == PILLAR)
		return (SPT_PILLAR);
	if (id == SKULL)
		return (SPT_SKULL);
	if (id == TABLE)
		return (SPT_TABLE);
	if (id == TABLEL)
		return (SPT_TABLEL);
	if (id == GUARD)
		return (SPT_GUARD1);
	if (id == MUTANT)
		return (SPT_MUT1);
	return (0);
}

float	get_angle_sprite_player(t_sprite sprite, t_data *data)
{
	float	ret;

	ret = data->player.rot_angle - atan2(sprite.y - data->player.y,
			sprite.x - data->player.x);
	if (ret > PI)
		ret -= TWO_PI;
	if (ret < -PI)
		ret += TWO_PI;
	return (fabs(ret));
}

int	get_sprite_action_dist(int id)
{
	if (id == GUARD)
		return (SPRITE_RANGE);
	if (id == MUTANT)
		return (SPRITE_RANGE / 2);
	return (INT_MAX);
}

t_bool	is_sprite_collidable(int id)
{
	return (ftex_is_in_set(id, COLLID_SPRITE));
}

t_bool	is_sprite_animated(int id)
{
	return (ftex_is_in_set(id, ANIMATED_SPRITE));
}
