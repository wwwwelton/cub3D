/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:12:55 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/02 07:00:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_commas(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == ',')
			i++;
		str++;
	}
	return (i);
}

static int	string_max_size(char **matrix)
{
	int	i;
	int	size;
	int	maxsize;

	maxsize = 0;
	i = -1;
	while (matrix[++i])
	{
		size = ft_strlen(matrix[i]);
		if (size > maxsize)
			maxsize = size;
	}
	return (maxsize);
}

static char	**insert_padding(char **matrix, int maxsize)
{
	int		size;
	int		i;
	char	*tmp;

	i = -1;
	while (matrix[++i])
	{
		size = ft_strlen(matrix[i]);
		if (size < maxsize)
		{
			tmp = malloc(sizeof(char) * maxsize + 1);
			ft_strlcpy(tmp, matrix[i], size + 1);
			ft_memset(tmp + size, ' ', maxsize - size);
			tmp[maxsize] = '\0';
			free(matrix[i]);
			matrix[i] = tmp;
		}
	}
	return (matrix);
}

char	**fetch_map_array(char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**ret;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = ft_get_next_line(fd);
	while (ftex_is_in_set(*tmp, "NSEWCF\n"))
	{
		free(tmp);
		tmp = ft_get_next_line(fd);
		if (!tmp)
			return (NULL);
	}
	line = ft_strdup("");
	while (tmp)
	{
		line = ft_strmerge(line, tmp);
		tmp = ft_get_next_line(fd);
	}
	ret = ft_split(line, '\n');
	ret = insert_padding(ret, string_max_size(ret));
	close(fd);
	free(line);
	return (ret);
}
