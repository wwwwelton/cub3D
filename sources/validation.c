/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:33:46 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/14 16:14:41 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_map_name_valid(t_data *data, char *mapname)
{
	char *dot;

	(void)data;
	dot = ft_strchr(mapname, '.');
	if (!dot)
		return(false);
	if (ft_strncmp(dot, ".cub", ft_strlen(dot)) || ft_strncmp(".cub", dot, 3))
	{
		printf("map name invalid: %s\n", mapname);
		return(false);
	}
	return (true);
}

t_bool	validation(t_data *data, int argc, char **argv)
{
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
	if (open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr_fd("map does not exist or incorrect permissions\n", 1);
		return (false);
	}
	else
		close(argv[1]);
	return (true);
}
