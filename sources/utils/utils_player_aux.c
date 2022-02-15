/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/14 22:54:15 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	decrease_step(float *move_step, float *side_step)
{
	*move_step /= 2;
	*side_step /= 2;
}

void	lock_view_angle(float *view_angle)
{
	if (*view_angle > VIEW_ANGLE)
		*view_angle = VIEW_ANGLE;
	if (*view_angle < -VIEW_ANGLE)
		*view_angle = -VIEW_ANGLE;
}

void	set_player_position(t_data *data, char **map)
{
	t_xy	xy;

	xy = get_coordinates(map, 0, 0);
	data->player.y = xy.x * TILE_SIZE + (TILE_SIZE / 2);
	data->player.x = xy.y * TILE_SIZE + (TILE_SIZE / 2);
}

char	get_player_direction(char **map)
{
	t_xy	xy;

	xy = get_coordinates(map, 0, 0);
	return (map[xy.x][xy.y]);
}

float	set_player_direction(char c)
{
	if (DEBUG)
		printf("%c\n", c);
	if (c == 'N')
		return (270 * (PI / 180));
	else if (c == 'E')
		return (360 * (PI / 180));
	else if (c == 'W')
		return (180 * (PI / 180));
	else if (c == 'S')
		return (90 * (PI / 180));
	else
		return (0);
}
