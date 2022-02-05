/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:12:55 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/04 22:36:39 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_char_adjacent_to(char **map, int x, int y, char c)
{
	if ((x > 0 && y > 0 && map[x - 1][y - 1] == c)
	|| (y > 0 && map[x][y - 1] == c)
	|| (map[x + 1] && y > 0 && map[x + 1][y - 1] == c)
	|| (x > 0 && map[x - 1][y] == c)
	|| (map[x + 1] && map[x + 1][y] == c)
	|| (x > 0 && map[x - 1][y + 1] == c)
	|| map[x][y + 1] == c
	|| (map[x + 1] && map[x + 1][y + 1] == c))
		return (true);
	return (false);
}

t_bool	is_border(char **map, int x, int y, char c)
{
	if (x == 0 || y == 0 || map[x][y + 1] == '\0' || map[x + 1] == NULL)
		return (true);
	if (map[x - 1][y - 1] == c
	|| map[x][y - 1] == c
	|| map[x + 1][y - 1] == c
	|| map[x - 1][y] == c
	|| map[x + 1][y] == c
	|| map[x - 1][y + 1] == c
	|| map[x][y + 1] == c
	|| map[x + 1][y + 1] == c)
		return (true);
	return (false);
}
