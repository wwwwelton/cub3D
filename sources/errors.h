#ifndef ERRORS_H
# define ERRORS_H

# define E_NOMAP "Error\nMap name not specified\nusage: ./cub3d (mapname)\n"
# define E_MAPDUP "Error\nMultiple maps provided\nusage: ./cub3d (mapname)\n"
# define E_MAPEXT "Error\nIncorrect map extension\nexpected: (map).cub\n"
# define E_MAPINVAL "Error\nMap does not exist or incorrect permissions\n"

# define E_TEXDUP "Error\nduplicated texture file"
# define E_TEXEXT "Error\nincorrect file type\nexpected: .xpm\n"
# define E_TEXINVAL "Error\nfile does not exist / incorrect permissions\n"

# define E_RGBRANGE "Error\ncolor value outside of acceptable range\n"
# define E_RGBMUCH "Error\ntoo many colors in color set\n"

# define E_IDINVAL "Error\n%s: Invalid identifier: %s\n"

#endif
