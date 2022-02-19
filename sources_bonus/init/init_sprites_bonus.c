/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:23:27 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/18 22:23:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	fill_sprite_data(t_sprite *sprite, int i, int j, char id)
{
	sprite->x = j * TILE_SIZE + (TILE_SIZE / 2);
	sprite->y = i * TILE_SIZE + (TILE_SIZE / 2);
	sprite->texture = id - 63;
}

void	init_sprites(t_data *data, char **map, int i, int j)
{
	static int	nb_sprites = 0;

	while (map[++i])
	{
		while (map[i][++j])
		{
			if (ftex_is_in_set(map[i][j], VALID_SPRITE))
				fill_sprite_data(&data->sprites[nb_sprites++], i, j, map[i][j]);
		}
		j = -1;
	}
	data->num_sprites = nb_sprites;
}
