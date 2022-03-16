/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:24:23 by jofelipe          #+#    #+#             */
/*   Updated: 2022/03/16 15:30:27 by jofelipe         ###   ########.fr       */
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
	if (ft_strncmp(dot, ".cub", ft_strlen(dot)) || ft_strncmp(".cub", dot, 4))
	{
		printf(E_MAPINVAL2, mapname);
		return (false);
	}
	return (true);
}

t_bool	print_error(char *error)
{
	ft_putstr_fd(error, 2);
	return (false);
}

t_bool	argument_validation(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (print_error(E_NOMAP));
	if (argc > 2)
		return (print_error(E_MAPDUP));
	if (is_map_name_valid(data, argv[1]) == false)
		return (print_error(E_MAPEXT));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(E_MAPINVAL));
	close(fd);
	return (true);
}
