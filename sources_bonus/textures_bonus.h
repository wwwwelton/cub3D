/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:16:42 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/14 23:17:48 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

# define TEXTURE3 "assets/images/no_redbrick.xpm"
# define TEXTURE4 "assets/images/we_redbrick.xpm"
# define TEXTURE5 "assets/images/so_redbrick.xpm"
# define TEXTURE6 "assets/images/ea_redbrick.xpm"

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

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef enum e_tex
{
	SCREEN,
	MAP,
	FRAME,
	TEX_NO,
	TEX_EA,
	TEX_SO,
	TEX_WE,
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
	EXIT,
	BLOCK,
	TEX_NB
}	t_tex;

#endif
