/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:47 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/30 23:50:40 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == OUTER)
				printf("%c", map[i][j]);
			else if (map[i][j] == ' ')
				printf("%c", ' ');
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
		j = -1;
	}
}

void	print_colored_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == OUTER)
				printf("\e[42m%c\e[0m", map[i][j]);
			else if (map[i][j] == INNER)
				printf("\e[44m%c\e[0m", map[i][j]);
			else if (ftex_is_in_set(map[i][j], "NSEW"))
				printf("\e[46m%c\e[0m", map[i][j]);
			else if (map[i][j] == ' ')
				printf("%c", ' ');
			else if (!ftex_is_in_set(map[i][j], "0123 NSEW"))
				printf("\e[45m%c\e[0m", map[i][j]);
			else
				printf("\e[41m%c\e[0m", map[i][j]);
		}
		printf("\n");
		j = -1;
	}
}
