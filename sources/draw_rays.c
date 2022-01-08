/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/08 03:31:59 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	dist(float ax, float ay, float bx, float by, float ang)
{
	(void)ang;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

static float degToRad(float a) { return a*M_PI/180.0;}
static float FixAng(float a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}


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
		1, 0, 1, 0, 2, 2, 2, 1,
		1, 1, 0, 0, 2, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	float	disT;
	int		color;

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
		int	vmt = 0, hmt = 0;
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
			if (mp > 0 && mp < mapX * mapY && map[mp] > 0)
			{
				hmt = map[mp] - 1;
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
			if (mp > 0 && mp < mapX * mapY && map[mp] > 0)
			{
				vmt = map[mp] - 1;
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
		float shade = 1;
		if (disV < disH)
		{
			hmt = vmt;
			shade = 0.5;
			rx = vx;
			ry = vy;
			disT = disV;
			color = RED_BLACK;
		}
		else
		{
			rx = hx;
			ry = hy;
			disT = disH;
			color = RED;
		}
		draw_line(&data->img_rays, px, py, rx, ry, RED);
		//Check Vertical Lines

		//Fix fisheye
		float ca = pa - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT = disT * cos(ca);
		//Fix fisheye

		float lineH = (mapS * 320) / disT;
		float ty_step = 32.0 / (float)lineH;
		float ty_off = 0;
		if (lineH > 320)
		{
			ty_off = (lineH - 320) / 2.0;
			lineH = 320;
		}
		float lineOff = 160 - lineH / 2;

		//draw walls
		int		y;
		float	ty = ty_off * ty_step;
		float	tx;
		if (shade == 1)
		{
			tx = (int) (rx / 2.0) % 32;
			if (ra > 180)
				tx = 31 - tx;
		}
		else
		{
			tx = (int) (ry / 2.0) % 32;
			if (ra > 90 && ra < 270)
				tx = 31 - tx;
		}
		for (y = 0; y < lineH; y++)
		{
			if (hmt)
				color = get_pixel_color(&data->img_tex1, ty, tx, 32, 32);
			else
				color = get_pixel_color(&data->img_tex2, ty, tx, 32, 32);
			draw_vert_pixel(&data->img_rays, r*8 + 530, y + lineOff, 8, color);
			ty += ty_step;
		}
		//draw walls

		//draw floors
		//draw ceiling
		for (y = lineOff + lineH; y < 320; y++)
		{
			float dy = y - (320 / 2.0);
			float deg = degToRad(ra);
			float raFix = cos(degToRad(FixAng(pa-ra)));

			tx = px / 2 + cos(deg) * 158 * 32 / dy / raFix;
			ty = py / 2 - sin(deg) * 158 * 32 / dy / raFix;
			color = get_pixel_color(&data->img_tex2, ty, tx, 32, 32);
			draw_vert_pixel(&data->img_rays, r*8 + 530, y, 8, GRAYF);
			draw_vert_pixel(&data->img_rays, r*8 + 530, 320 - y, 8, GRAYC);
		}
		//draw floors
		//draw ceiling

		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}
