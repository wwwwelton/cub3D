/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/22 02:38:15 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	sort_visible_sprites(t_sprite *visible_sprites, int num_sprites)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < num_sprites)
	{
		j = -1;
		while (++j < num_sprites)
		{
			if (visible_sprites[i].distance > visible_sprites[j].distance)
			{
				temp = visible_sprites[i];
				visible_sprites[i] = visible_sprites[j];
				visible_sprites[j] = temp;
			}
		}
	}
}
