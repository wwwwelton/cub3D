/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/23 15:03:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	get_sprite_dist(t_sprite sprite, t_data *data)
{
	float	ret;

	ret = distance_between_points(sprite.x,
			sprite.y, data->player.x, data->player.y);
	return (ret);
}

int	map_has_sprite_at(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y < 0 || map_y > (map_height(data) - 1)
		|| map_x < 0 || map_x > (map_width(data) - 1))
	{
		return (false);
	}
	return (ftex_is_in_set(data->map[map_y][map_x], VALID_SPRITE));
}

int	has_sprite_collision_at(float x, float y, t_data *data)
{
	int			n;
	int			i;
	int			j;
	t_sprite	*sprite;

	if (!map_has_sprite_at(x, y, data))
		return (false);
	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	n = -1;
	while (++n < data->num_visible_sprites)
	{
		sprite = &data->visible_sprites[n];
		if (sprite->i == i && sprite->j == j && sprite->collidable)
			return (true);
	}
	return (false);
}

int	has_sprite_hittable_at(float x, float y, t_data *data)
{
	int			n;
	int			i;
	int			j;
	t_sprite	*sprite;

	if (!map_has_sprite_at(x, y, data))
		return (false);
	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	n = -1;
	while (++n < data->num_visible_sprites)
	{
		sprite = &data->visible_sprites[n];
		if (sprite->i == i && sprite->j == j
			&& sprite->collidable && !sprite->hitted)
			return (true);
	}
	return (false);
}

void	hit_sprite_at_pos(float x, float y, t_data *data)
{
	int			n;
	int			i;
	int			j;
	t_sprite	*sprite;

	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	n = -1;
	while (++n < data->num_visible_sprites)
	{
		sprite = &data->visible_sprites[n];
		if (sprite->i == i && sprite->j == j)
			data->sprites[sprite->index].hitted = true;
	}
}
