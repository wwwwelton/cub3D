/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/19 19:05:24 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_sprite_texture(int id)
{
	if (id == ARMOR)
		return (SPT_ARMOR);
	if (id == BARREL)
		return (SPT_BARREL);
	if (id == GUARD)
		return (SPT_GUARD);
	if (id == TABLE)
		return (SPT_TABLE);
	if (id == TABLEL)
		return (SPT_TABLEL);
	return (0);
}

t_bool	is_sprite_collidable(int id)
{
	return (ftex_is_in_set(id, COLLID_SPRITE));
}

t_bool	is_sprite_hittable(int id)
{
	return (ftex_is_in_set(id, HITTABLE_SPRITE));
}

t_bool	is_sprite_animated(int id)
{
	return (ftex_is_in_set(id, ANIMATED_SPRITE));
}
