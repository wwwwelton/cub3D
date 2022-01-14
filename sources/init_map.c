/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:47 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/14 17:00:53 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**fetch_map_array(char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**ret;

	fd = open(argv[1], O_RDONLY);
	tmp = ft_get_next_line(fd);
	line = ft_strdup("");
	while (tmp)
	{
		line = ft_strmerge(line, tmp);
		tmp = ft_get_next_line(fd);
	}
	printf("%s", line);
	ret = ft_split(line, '\n');
	free(line);
	return (ret);

}

void	init_map(t_data *data, char **argv)
{
	data->map.charmatrix = fetch_map_array(argv);
}
