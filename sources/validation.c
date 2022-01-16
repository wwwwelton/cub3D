/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:33:46 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/15 21:00:46 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_map_name_valid(t_data *data, char *mapname)
{
	char	*dot;

	(void)data;
	dot = ft_strrchr(mapname, '.');
	if (!dot)
		return (false);
	if (ft_strncmp(dot, ".cub", ft_strlen(dot)) || ft_strncmp(".cub", dot, 3))
	{
		printf("map name invalid: %s\n", mapname);
		return (false);
	}
	return (true);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

t_bool	map_validation(char **map)
{
	t_bool	boolean;

	outline_polygon(map);
	if (is_player_polygon_closed(map))
		boolean = true;
	else
		boolean = false;
	printf("outline\n");
	print_map(map);
	free_matrix(map);
	return (boolean);
}

t_bool	argument_validation(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_putstr_fd("map name not specified\nusage: ./cub3d (mapname)\n", 1);
		return (false);
	}
	if (argc > 2)
	{
		ft_putstr_fd("multiple maps provided\nusage: ./cub3d (mapname)\n", 1);
		return (false);
	}
	if (is_map_name_valid(data, argv[1]) == false)
	{
		ft_putstr_fd("incorrect map name\nexpected: (map).cub\n", 1);
		return (false);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("map does not exist or incorrect permissions\n", 1);
		return (false);
	}
	close(fd);
	return (true);
}

t_bool	validation(t_data *data, int argc, char **argv)
{
	if (!argument_validation(data, argc, argv))
		return (false);
	if (!map_validation(fetch_map_array(argv)))
		return (false);
	return (true);
}
