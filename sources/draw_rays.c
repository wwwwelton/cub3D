/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/06 01:49:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	dist(float ax, float ay, float bx, float by, float ang)
{
	(void)ang;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}


void	draw_rays(t_data *data)
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx = 0;
	float	ry = 0;
	float	ra;
	float	xo = 0;
	float	yo = 0;
	float	aTan;
	float	nTan;
	float	py;
	float	px;
	float	pa;
	int		mapX = 8, mapY = 8, mapS = 64;
	int		map[64] =
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 0, 0, 1, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	float	disT;
	t_img	*img;

	ra = data->player.pa - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	pa = data->player.pa;
	py = data->player.py;
	px = data->player.px;
	for (r = 0; r < 60; r++)
	{
		// //Check Horizontal Lines
		dof = 0;
		float disH = 1000000, hx = px, hy = py;
		aTan = -1 / tan (ra);
		if (ra > PI)
		{
			ry = (((int)py >> 6) << 6) - 0.0001;
			rx = (py - ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)py >> 6) << 6) + 64;
			rx = (py - ry) * aTan + px;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				hx = rx;
				hy = ry;
				disH = dist(px, py, hx, hy, ra);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		// //Check Horizontal Lines

		//Check Vertical Lines
		dof = 0;
		float disV = 1000000, vx = px, vy = py;
		nTan = -tan(ra);
		if (ra > P2 && ra < P3)
		{
			rx = (((int)px >> 6) << 6) - 0.0001;
			ry = (px - rx) * nTan + py;
			xo = -64;
			yo = -xo * nTan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = (((int)px >> 6) << 6) + 64;
			ry = (px - rx) * nTan + py;
			xo = 64;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				vx = rx;
				vy = ry;
				disV = dist(px, py, vx, vy, ra);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		if (disV < disH)
		{
			rx = vx;
			ry = vy;
			disT = disV;
			img = &data->img_pixel4;
		}
		else
		{
			rx = hx;
			ry = hy;
			disT = disH;
			img = &data->img_pixel5;
		}
		draw_line(data, &data->img_pixel2, px, py, rx, ry);
		//Check Vertical Lines
		//Draw 3D Walls
		//Fix fisheye
		float ca = pa - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT = disT * cos(ca);
		//Fix fisheye
		float lineH = (mapS * 320) / disT;
		if (lineH > 320)
			lineH = 320;
		float lineO = 160 - lineH / 2;
		draw_line(data, img, r * 8 + 530, lineO, r * 8 + 530, lineH + lineO);
		//Draw 3D Walls
		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}
