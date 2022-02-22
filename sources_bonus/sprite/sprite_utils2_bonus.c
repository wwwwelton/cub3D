/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/22 04:37:57 by wleite           ###   ########.fr       */
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
		return (SPT_GUARD1);
	if (id == TABLE)
		return (SPT_TABLE);
	if (id == TABLEL)
		return (SPT_TABLEL);
	if (id == MUTANT)
		return (SPT_MUT1);
	return (0);
}

t_bool	is_sprite_collidable(int id)
{
	return (ftex_is_in_set(id, COLLID_SPRITE));
}

t_bool	is_sprite_animated(int id)
{
	return (ftex_is_in_set(id, ANIMATED_SPRITE));
}

t_bool	check_sprite_range(t_sprite sprite)
{
	return (sprite.distance < SPRITE_RANGE);
}
