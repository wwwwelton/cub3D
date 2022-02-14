/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:00 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/14 18:47:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define CLEAR "\e[1;1H\e[2J"
# define DEBUG 0

# define MENU 0
# define GAME 1
# define OPTIONS 3

# define NORTH 1
# define WEST 2
# define SOUTH 3
# define EAST 4

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
# define VALID_PLAYER "NSEW"
# define VALID_MAP "01"

# define FRAME_DELAY 500

# define MINIMAP_SCALE_FACTOR 0.1
# define TILE_SIZE 64

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define IMG_WIDTH 1920
# define IMG_HEIGHT 1080

# define NUM_RAYS WIN_WIDTH
# define FLT_MAX 3.40282346638528859812e+38F
# define FOV_ANGLE 1.0472
# define FOG_DIST 400
# define FOG_SIDE 0.7

# define PLAYER_SIZE 64
# define VIEW_ANGLE 400

# define RED 0xff0000
# define RED_BLACK 0xd20000
# define YELLOW 0xE3E316
# define BLACK 0x000000
# define BLACKB 0x010101
# define WHITE 0xFFFFFF
# define GRAY 0x5c5c5c
# define GRAYC 0x383838
# define GRAYF 0x707070
# define PINK 0xff00fe
# define BLUE 0x0171FF
# define BLUE2 0x1b4382
# define GRAY2 0x1d2024

#endif
