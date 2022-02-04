/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player_aux2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/04 18:29:19 by wleite           ###   ########.fr       */
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
