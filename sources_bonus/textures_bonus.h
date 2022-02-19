/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:16:42 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/19 04:17:18 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

# define PATHLOGO "assets/images/cube_logo.xpm"
# define PATHBG "assets/images/background_menu.xpm"
# define PATHSTART "assets/images/game_start.xpm"
# define PATHOPTION "assets/images/options.xpm"
# define PATHARROW "assets/images/seta.xpm"
# define PATHSENSI "assets/images/mouse_speed.xpm"
# define PATHMSPD "assets/images/move_speed.xpm"
# define PATHRSPD "assets/images/rotation_speed.xpm"
# define PATHBACK "assets/images/back_to_menu.xpm"
# define PATHRESUME "assets/images/resume_game.xpm"
# define PATHEXIT "assets/images/exit_game.xpm"
# define PATHCROSSHAIR "assets/images/crosshair.xpm"
# define PATHHUDFRAME "assets/images/hud_frame.xpm"
# define PATHHUDBLOCK "assets/images/hud_block.xpm"
# define PATHNOIMAGE "assets/images/no_image.xpm"

# define PATHFPS0 "assets/images/fps_numbers/0.xpm"
# define PATHFPS1 "assets/images/fps_numbers/1.xpm"
# define PATHFPS2 "assets/images/fps_numbers/2.xpm"
# define PATHFPS3 "assets/images/fps_numbers/3.xpm"
# define PATHFPS4 "assets/images/fps_numbers/4.xpm"
# define PATHFPS5 "assets/images/fps_numbers/5.xpm"
# define PATHFPS6 "assets/images/fps_numbers/6.xpm"
# define PATHFPS7 "assets/images/fps_numbers/7.xpm"
# define PATHFPS8 "assets/images/fps_numbers/8.xpm"
# define PATHFPS9 "assets/images/fps_numbers/9.xpm"

# define PATHDOOR "assets/images/door.xpm"

# define PATHARMOR "assets/images/sprites/armor.xpm"
# define PATHBARREL "assets/images/sprites/barrel.xpm"
# define PATHGUARD "assets/images/sprites/guard.xpm"
# define PATHTABLEL "assets/images/sprites/table_lamp.xpm"
# define PATHTABLE "assets/images/sprites/table.xpm"

# define PATHGUARD1 "assets/images/sprites/animated/guard1.xpm"
# define PATHGUARD2 "assets/images/sprites/animated/guard2.xpm"
# define PATHGUARD3 "assets/images/sprites/animated/guard3.xpm"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef enum e_tex
{
	SCREEN,
	MAP,
	FRAME,
	SPRITE,
	TEX_NO,
	TEX_EA,
	TEX_SO,
	TEX_WE,
	TEX_DOOR,
	MEN_LOGO,
	MEN_BG,
	MEN_START,
	MEN_OPT,
	SENSI,
	RESUME,
	BACK,
	RSPD,
	MSPD,
	ARROW,
	CROSSHAIR,
	HUDFRAME,
	FPS,
	EXIT,
	BLOCK,
	FPS_0,
	FPS_1,
	FPS_2,
	FPS_3,
	FPS_4,
	FPS_5,
	FPS_6,
	FPS_7,
	FPS_8,
	FPS_9,
	SPT_ARMOR,
	SPT_BARREL,
	SPT_GUARD,
	SPT_GUARD1,
	SPT_GUARD2,
	SPT_GUARD3,
	SPT_TABLE,
	SPT_TABLEL,
	TEX_NB
}	t_tex;

#endif
