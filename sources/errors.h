/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:19:05 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/19 01:15:58 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define E_NOMAP "Error\nMap name not specified\nusage: ./cub3d (mapname)\n"
# define E_MAPDUP "Error\nMultiple maps provided\nusage: ./cub3d (mapname)\n"
# define E_MAPEXT "Error\nIncorrect map extension\nexpected: (map).cub\n"
# define E_MAPINVAL "Error\nMap does not exist or incorrect permissions\n"
# define E_MAPINVAL2 "Error\nmap name invalid: %s\n"
# define E_MAPINVAL3 "Error\ninvalid characters in the map\n"
# define E_MAPOPEN "Error\nOuter walls are open\n"
# define E_MAPOPEN2 "Error\nInner walls are open"

# define E_NOTEX "Error\nmissing texture\n"
# define E_TEXDUP "Error\nduplicated texture file"
# define E_TEXEXT "Error\nincorrect file type\nexpected: .xpm\n"
# define E_TEXINVAL "Error\nfile does not exist / incorrect permissions\n"

# define E_NORGB "Error\nMissing color\n"
# define E_RGBRANGE "Error\ncolor value outside of acceptable range\n"
# define E_RGBMUCH "Error\ntoo many colors in color set\n"

# define E_IDINVAL "Error\n%s: Invalid identifier: %s\n"

#endif
