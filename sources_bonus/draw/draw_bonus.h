/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:59:34 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/16 17:54:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H

void	draw_map(t_data *data, char **map, int x, int y);

//wall
void	draw_wall(t_data *data);
void	init_wall_data(t_wall_data *wall, t_player player);
int		get_wall_texture(t_ray ray);
int		get_wall_pixel_color(t_img texture, t_wall_data *wall);
void	check_inverse_offset_x(t_ray ray, int *texture_offset_x);
int		get_texture_offset_x(t_ray ray);

#endif
