/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:46:11 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/23 17:55:43 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_BONUS_H
# define GRAPHICS_BONUS_H

typedef struct s_fill
{
	int	x;
	int	y;
	int	xlen;
	int	ylen;
}	t_fill;

typedef struct s_menu_elem
{
	t_img	*src;
	t_img	*dst;
	int		x;
	int		y;
}	t_menu_elem;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

void	alpha_layer(t_img *from, t_img *to, t_xy xy, float alpha);
t_xy	layer_vars(int x, int y);

void	fill(t_img *img, t_fill fill, int color);
t_fill	fillparams(int x, int y, int xlen, int ylen);

void	copy_layer(t_img *from, t_img *to, int x, int y);
int		blend_colors(int color1, int color2, float alpha1, float alpha2);
void	change_color_intensity(int *color, float factor);
int		get_color(int r, int g, int b);
t_img	*resize_image(t_img *image_to_scale, float scale, t_data *data);

#endif
