/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:00 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/14 23:17:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# define CLEAR "\e[1;1H\e[2J"
# define DEBUG 0

# define MENU 0
# define GAME 1
# define OPTIONS 2

# define YOFF 250
# define XOFF 100
# define OPTYOFF 200
# define OPTXOFF 100

# define PI 3.14159265
# define TWO_PI 6.28318530

# define EDGE '9'
# define OUTER '!'
# define INNER '@'
# define FILLER '#'
# define VALID_MAP_CHARS "01 NSEW\n"
# define VALID_PLAYER "NSEW"
# define VALID_MAP "01"
# define VALID_ID "NSEWCF\n"

# define FRAME_DELAY 500

# define TILE_SIZE 64

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define NUM_RAYS WIN_WIDTH
# define FLT_MAX 3.40282346638528859812e+38F
# define FOV_ANGLE 1.0472
# define FOG_DIST 400
# define FOG_SIDE 0.7

# define PLAYER_SIZE TILE_SIZE
# define VIEW_ANGLE 400

# define RED 0xff0000
# define YELLOW 0xE3E316
# define BLACK 0x000000
# define BLACKB 0x010101
# define WHITE 0xFFFFFF
# define GRAY 0x5c5c5c
# define BLUE 0x1b4382

#endif