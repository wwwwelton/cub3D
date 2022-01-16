/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:24:23 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/16 04:37:59 by jofelipe         ###   ########.fr       */
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
		printf(E_MAPINVAL2, mapname);
		return (false);
	}
	return (true);
}

t_bool	argument_validation(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_putstr_fd(E_NOMAP, 2);
		return (false);
	}
	if (argc > 2)
	{
		ft_putstr_fd(E_MAPDUP, 2);
		return (false);
	}
	if (is_map_name_valid(data, argv[1]) == false)
	{
		ft_putstr_fd(E_MAPEXT, 2);
		return (false);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(E_MAPINVAL, 2);
		return (false);
	}
	close(fd);
	return (true);
}
