/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:16:42 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/26 20:34:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

# define PATHLOGO "assets/images/cube_logo.xpm"
# define PATHBG "assets/images/background_menu.xpm"
# define PATHSTART "assets/images/game_start.xpm"
# define PATHOPTION "assets/images/options.xpm"
# define PATHARROW "assets/images/seta.xpm"
# define PATHSENSI "assets/images/vertical_speed.xpm"
# define PATHMSPD "assets/images/move_speed.xpm"
# define PATHRSPD "assets/images/rotation_speed.xpm"
# define PATHBACK "assets/images/back_to_menu.xpm"
# define PATHRESUME "assets/images/resume_game.xpm"
# define PATHEXIT "assets/images/exit_game.xpm"
# define PATHCROSSHAIR "assets/images/crosshair.xpm"
# define PATHHUDFRAME "assets/images/hud_frame.xpm"
# define PATHHUDBLOCK "assets/images/hud_block.xpm"
# define PATHNOIMAGE "assets/images/no_image.xpm"

# define PATHWEAPON1 "assets/images/weapon/weapon1.xpm"
# define PATHWEAPON2 "assets/images/weapon/weapon2.xpm"
# define PATHWEAPON3 "assets/images/weapon/weapon3.xpm"

# define PATHFPS0 "assets/images/fps/0.xpm"
# define PATHFPS1 "assets/images/fps/1.xpm"
# define PATHFPS2 "assets/images/fps/2.xpm"
# define PATHFPS3 "assets/images/fps/3.xpm"
# define PATHFPS4 "assets/images/fps/4.xpm"
# define PATHFPS5 "assets/images/fps/5.xpm"
# define PATHFPS6 "assets/images/fps/6.xpm"
# define PATHFPS7 "assets/images/fps/7.xpm"
# define PATHFPS8 "assets/images/fps/8.xpm"
# define PATHFPS9 "assets/images/fps/9.xpm"

# define PATHDOOR "assets/images/door.xpm"
# define PATHDOORSIDE "assets/images/door_side.xpm"

# define PATHARMOR "assets/images/sprites/armor.xpm"
# define PATHBARREL "assets/images/sprites/barrel.xpm"
# define PATHDRUM "assets/images/sprites/drum.xpm"
# define PATHMINITREE "assets/images/sprites/mini_tree.xpm"
# define PATHPILLAR "assets/images/sprites/pillar.xpm"
# define PATHSKULL "assets/images/sprites/skull.xpm"
# define PATHTABLEL "assets/images/sprites/table_lamp.xpm"
# define PATHTABLE "assets/images/sprites/table.xpm"

# define PATHBBLOCK "assets/images/blue_block.xpm"
# define PATHRBLOCK "assets/images/red_block.xpm"
# define PATHPBLOCK "assets/images/purple_block.xpm"
# define PATHJBLOCK "assets/images/joao.xpm"
# define PATHWBLOCK "assets/images/welton.xpm"

# define PATHGUARD1 "assets/images/sprites/animated/guard1.xpm"
# define PATHGUARD2 "assets/images/sprites/animated/guard2.xpm"
# define PATHGUARD3 "assets/images/sprites/animated/guard3.xpm"
# define PATHGUARD4 "assets/images/sprites/animated/guard4.xpm"
# define PATHGUARD5 "assets/images/sprites/animated/guard5.xpm"
# define PATHGUARD6 "assets/images/sprites/animated/guard6.xpm"

# define PATHMUT1 "assets/images/sprites/animated/mutant1.xpm"
# define PATHMUT2 "assets/images/sprites/animated/mutant2.xpm"
# define PATHMUT3 "assets/images/sprites/animated/mutant3.xpm"
# define PATHMUT4 "assets/images/sprites/animated/mutant4.xpm"
# define PATHMUT5 "assets/images/sprites/animated/mutant5.xpm"
# define PATHMUT6 "assets/images/sprites/animated/mutant6.xpm"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef enum e_tex
{
	SCREEN,
	MAP,
	FRAME,
	SPRITE,
	WEAPON,
	TEX_NO,
	TEX_EA,
	TEX_SO,
	TEX_WE,
	TEX_BBLOCK,
	TEX_RBLOCK,
	TEX_PBLOCK,
	TEX_JBLOCK,
	TEX_WBLOCK,
	TEX_DOOR,
	TEX_DOOR_SIDE,
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
	WEAPON_1,
	WEAPON_2,
	WEAPON_3,
	SPT_ARMOR,
	SPT_BARREL,
	SPT_DRUM,
	SPT_MINITREE,
	SPT_PILLAR,
	SPT_SKULL,
	SPT_TABLE,
	SPT_TABLEL,
	SPT_GUARD1,
	SPT_GUARD2,
	SPT_GUARD3,
	SPT_GUARD4,
	SPT_GUARD5,
	SPT_GUARD6,
	SPT_MUT1,
	SPT_MUT2,
	SPT_MUT3,
	SPT_MUT4,
	SPT_MUT5,
	SPT_MUT6,
	TEX_NB
}	t_tex;

#endif
