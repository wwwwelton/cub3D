/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/22 06:08:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	guard_hit_player(t_sprite *sprite, t_data *data)
{
	t_bool	hit;

	hit = 0;
	if (sprite->in_range && !sprite->hitted)
	{
		if (sprite->frame == 0)
			sprite->texture = SPT_GUARD2;
		if (sprite->frame == 1)
		{
			sprite->texture = SPT_GUARD3;
			sprite->frame = -1;
			hit = 1;
		}
		if (data->frame.cycle % 4 == 0)
			sprite->frame++;
		sprite->frame = sprite->frame % 2;
		return (hit);
	}
	return (hit);
}

static void	animate_guard(t_sprite *sprite, t_data *data)
{
	if (!sprite->in_range && !sprite->hitted)
		sprite->texture = SPT_GUARD2;
	if (guard_hit_player(sprite, data))
		data->player.hitted = 1;
	if (sprite->hitted && sprite->collidable)
	{
		if (sprite->frame > 2)
			sprite->collidable = 0;
		if (sprite->frame == 0)
			sprite->texture = SPT_GUARD4;
		if (sprite->frame == 1)
			sprite->texture = SPT_GUARD5;
		if (sprite->frame == 2)
			sprite->texture = SPT_GUARD6;
		if (data->frame.cycle % 6 == 0)
			sprite->frame++;
	}
}

static void	animate_mutant(t_sprite *sprite, t_data *data)
{
	if (sprite->in_range && !sprite->hitted)
		sprite->texture = SPT_MUT2;
	if (sprite->hitted && sprite->collidable)
	{
		if (sprite->frame > 2)
			sprite->collidable = 0;
		if (sprite->frame == 0)
			sprite->texture = SPT_MUT3;
		if (sprite->frame == 1)
			sprite->texture = SPT_MUT4;
		if (sprite->frame == 2)
			sprite->texture = SPT_MUT5;
		if (data->frame.cycle % 6 == 0)
			sprite->frame++;
	}
}

static void	animate_weapon(t_data *data)
{
	if (data->player.action_shoot)
	{
		if (data->player.frame < 2)
		{
			data->player.weapon = WEAPON_2;
			data->player.frame = 2;
		}
		else
		{
			data->player.weapon = WEAPON_3;
			data->player.frame = 3;
		}
	}
	else
	{
		data->player.frame = 0;
		data->player.weapon = WEAPON_1;
	}
	data->player.frame = (data->frame.cycle % 4);
}

void	update_animations(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_sprites)
	{
		if (data->sprites[i].id == GUARD)
			animate_guard(&data->sprites[i], data);
		if (data->sprites[i].id == MUTANT)
			animate_mutant(&data->sprites[i], data);
	}
	animate_weapon(data);
}
