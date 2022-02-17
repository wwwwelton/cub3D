/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/16 22:59:51 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	map_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

int	map_width(t_data *data)
{
	return (ft_strlen(data->map[0]));
}

int	is_inside_map(float x, float y, t_data *data)
{
	if (x >= 0 && x <= map_width(data) * TILE_SIZE
		&& y >= 0 && y <= map_height(data) * TILE_SIZE)
	{
		return (true);
	}
	return (false);
}
