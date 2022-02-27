/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:00 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/27 19:11:39 by jofelipe         ###   ########.fr       */
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

# define FPSXOFF 35
# define FPSYOFF 20

# define PI 3.14159265
# define TWO_PI 6.28318530

# define EDGE '9'
# define OUTER '!'
# define INNER '@'
# define FILLER '#'
# define VALID_PLAYER "NSEWP"
# define VALID_MAP "01234567DHabcdefghmn"
# define VALID_ID "NSEWCFDH\n"
# define VALID_MAP_CHARS "01234567 NSEWDHabcdefghmn\n"
# define VALID_SPRITE "abcdefghmn"
# define SSPRITE "abcdefghmnD"
# define VALID_WALLS "!@234567DGFZY"
# define VALID_DOOR_WALLS "GFZY"

# define COLLID_SPRITE "abcdeghmn"
# define ANIMATED_SPRITE "mn"

# define ARMOR 'a'
# define BARREL 'b'
# define DRUM 'c'
# define MINITREE 'd'
# define PILLAR 'e'
# define SKULL 'f'
# define TABLE 'g'
# define TABLEL 'h'

# define MUTANT 'm'
# define GUARD 'n'

# define DOOR 'D'

# define DOOR_WALL1 'G'
# define DOOR_WALL2 'F'
# define DOOR_WALL3 'Z'
# define DOOR_WALL4 'Y'

# define BBLOCK '2'
# define RBLOCK '3'
# define PBLOCK '4'
# define JBLOCK '5'
# define WBLOCK '6'
# define TBLOCK '7'

# define FRAME_DELAY 500
# define ANIMATION_DELAY 100

# define NUM_SPRITES 100
# define EPSILON 0.2

# define TILE_SIZE 64

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

# define NUM_RAYS WIN_WIDTH
# define FOV_ANGLE 1.0472
# define FOG_DIST 400
# define FOG_SIDE 0.7

# define DOOR_DIST 150
# define SHOT_DIST 550
# define SPRITE_RANGE 550

# define PLAYER_SIZE TILE_SIZE
# define VIEW_ANGLE 400

# define RED 0xff0000
# define YELLOW 0xE3E316
# define BLACK 0x000000
# define BLACKB 0x010101
# define WHITE 0xFFFFFF
# define GRAY 0x5c5c5c
# define BLUE 0x1b4382
# define GREEN 0x006262
# define PINK 0xFF00FF

#endif
