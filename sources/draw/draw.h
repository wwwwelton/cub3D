/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:59:34 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/14 23:33:54 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

//wall
void	draw_wall(t_data *data);
void	init_wall_data(t_wall_data *wall, t_player player);
int		get_wall_facing_side(t_ray ray);
int		get_wall_pixel_color(t_img texture, t_wall_data *wall);
void	check_inverse_offset_x(t_ray ray, int *texture_offset_x);
int		get_texture_offset_x(t_ray ray);

#endif
