/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:58:37 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/20 06:23:59 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief parameters to fill function
 *
 * @param x the starting x position
 * @param y the starting y position
 * @param xlen the length of the rectangle
 * @param ylen the height of the rectangle
 * @return t_fill
 */
t_fill	fillparams(int x, int y, int xlen, int ylen)
{
	t_fill	fill;

	fill.x = x;
	fill.y = y;
	fill.xlen = xlen;
	fill.ylen = ylen;
	return (fill);
}

/**
 * @brief fills a rectangle
 *
 * @param img the image to be filled
 * @param fill the parameters of the rectangle
 * @param color the color in hex format
 */
void	fill(t_img *img, t_fill fill, int color)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	if (fill.xlen == 0)
		fill.xlen = WIN_HEIGHT; //change to img height later
	if (fill.ylen == 0)
		fill.xlen = WIN_WIDTH; //change to img width later
	while (++j < fill.xlen)
	{
		while (++i < fill.ylen)
			img->dump[(j + fill.y) + (i + fill.x) * img->size_l / 4] = color;
		i = -1;
	}
}
