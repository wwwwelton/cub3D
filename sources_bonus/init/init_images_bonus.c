/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/19 04:17:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_bool	init_xpm_textures(t_data *data)
{
	static t_bool	valid = true;

	init_xpm(data, &data->img[TEX_NO], data->params.north, &valid);
	init_xpm(data, &data->img[TEX_EA], data->params.east, &valid);
	init_xpm(data, &data->img[TEX_SO], data->params.south, &valid);
	init_xpm(data, &data->img[TEX_WE], data->params.west, &valid);
	init_xpm(data, &data->img[TEX_DOOR], PATHDOOR, &valid);
	init_xpm(data, &data->img[MEN_LOGO], PATHLOGO, &valid);
	init_xpm(data, &data->img[MEN_BG], PATHBG, &valid);
	init_xpm(data, &data->img[MEN_START], PATHSTART, &valid);
	init_xpm(data, &data->img[MEN_OPT], PATHOPTION, &valid);
	init_xpm(data, &data->img[SENSI], PATHSENSI, &valid);
	init_xpm(data, &data->img[RESUME], PATHRESUME, &valid);
	init_xpm(data, &data->img[BACK], PATHBACK, &valid);
	init_xpm(data, &data->img[RSPD], PATHRSPD, &valid);
	init_xpm(data, &data->img[MSPD], PATHMSPD, &valid);
	init_xpm(data, &data->img[ARROW], PATHARROW, &valid);
	init_xpm(data, &data->img[BLOCK], PATHHUDBLOCK, &valid);
	init_xpm(data, &data->img[CROSSHAIR], PATHCROSSHAIR, &valid);
	init_xpm(data, &data->img[HUDFRAME], PATHHUDFRAME, &valid);
	init_xpm(data, &data->img[EXIT], PATHEXIT, &valid);
	return (valid);
}

t_bool	init_fps_textures(t_data *data)
{
	static t_bool	valid = true;

	init_xpm(data, &data->img[FPS_0], PATHFPS0, &valid);
	init_xpm(data, &data->img[FPS_1], PATHFPS1, &valid);
	init_xpm(data, &data->img[FPS_2], PATHFPS2, &valid);
	init_xpm(data, &data->img[FPS_3], PATHFPS3, &valid);
	init_xpm(data, &data->img[FPS_4], PATHFPS4, &valid);
	init_xpm(data, &data->img[FPS_5], PATHFPS5, &valid);
	init_xpm(data, &data->img[FPS_6], PATHFPS6, &valid);
	init_xpm(data, &data->img[FPS_7], PATHFPS7, &valid);
	init_xpm(data, &data->img[FPS_8], PATHFPS8, &valid);
	init_xpm(data, &data->img[FPS_9], PATHFPS9, &valid);
	return (valid);
}

t_bool	init_sprite_textures(t_data *data)
{
	static t_bool	valid = true;

	init_xpm(data, &data->img[SPT_ARMOR], PATHARMOR, &valid);
	init_xpm(data, &data->img[SPT_BARREL], PATHBARREL, &valid);
	init_xpm(data, &data->img[SPT_GUARD], PATHGUARD, &valid);
	init_xpm(data, &data->img[SPT_GUARD1], PATHGUARD1, &valid);
	init_xpm(data, &data->img[SPT_GUARD2], PATHGUARD2, &valid);
	init_xpm(data, &data->img[SPT_GUARD3], PATHGUARD3, &valid);
	init_xpm(data, &data->img[SPT_TABLE], PATHTABLE, &valid);
	init_xpm(data, &data->img[SPT_TABLEL], PATHTABLEL, &valid);
	return (valid);
}
