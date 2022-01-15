/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:47 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/14 23:43:21 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	string_max_size(char **matrix)
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

char	**insert_padding(char **matrix, int maxsize)
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
	int		i;

	i = -1;
	fd = open(argv[1], O_RDONLY);
	while (++i < 6)
	{
		tmp = ft_get_next_line(fd);
		free(tmp);
	}
	tmp = ft_get_next_line(fd);
	line = ft_strdup("");
	while (tmp)
	{
		line = ft_strmerge(line, tmp);
		tmp = ft_get_next_line(fd);
	}
	printf("%s", line);
	ret = ft_split(line, '\n');
	ret = insert_padding(ret, string_max_size(ret));
	close(fd);
	free(line);
	return (ret);
}

t_bool	is_char_adjacent(char **map, int x, int y, char c)
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

void	outline_polygon(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++x])
	{
		while (map[x][++y])
			if (map[x][y] == '1')
				if (is_char_adjacent(map, x, y, ' ') == true)
					map[x][y] = EDGE;
		y = -1;
	}
}

t_bool	ftex_is_in_set(char c, char *set)
{
	if (!set)
		return (false);
	while (*set)
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}

int	check_end(char **map, int x, int y)
{
	return ((y > 0 && map[x][y + 1] == '!' && map[x][y - 1] == '!')
	|| (x > 0 && map[x + 1] && map[x + 1][y] == '!' && map[x - 1][y] == '!')
	|| (x > 0 && map[x - 1][y] == '!' && map[x][y + 1] == '!')
	|| (x > 0 && y > 0 && map[x][y - 1] == '!' && map[x - 1][y] == '!')
	|| (y > 0 && map[x + 1] && map[x + 1][y] == '!' && map[x][y - 1] == '!')
	|| (map[x + 1] && map[x + 1][y] == '!' && map[x][y + 1] == '!'));
}

t_bool	crawl_polygon(char **map, int x, int y)
{
	while (1)
	{
		if (map[x + 1] && map[x + 1][y] == EDGE)
			map[x++][y] = '!';
		else if (y > 0 && map[x][y - 1] == EDGE)
			map[x][y--] = '!';
		else if (x > 0 && map[x - 1][y] == EDGE)
			map[x--][y] = '!';
		else if (map[x][y + 1] == EDGE)
			map[x][y++] = '!';
		else if (check_end(map, x, y))
		{
			printf("success\n");
			return (true);
		}
		else
		{
			printf("failure\n");
			return (false);
		}
	}
}

t_bool	is_player_polygon_closed(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++x])
	{
		printf("%s\n", map[x]);
		while (map[x][++y])
			if (ftex_is_in_set(map[x][y], "NSEW"))
				break ;
	if (ftex_is_in_set(map[x][y], "NSEW"))
				break ;
		y = -1;
	}
	if (x == 0 || map[x][y + 1] == '\0')
		return (false);
	while (map[x][y] && map[x][y] != '9')
		y++;
	if (crawl_polygon(map, x, y))
		return (true);
	return (false);
}

void	map_validation(char **map)
{
	outline_polygon(map);
	is_player_polygon_closed(map);
	printf("outline\n");
	int	i = -1;
	int	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '!')
				printf("\e[42m%c\e[0m", map[i][j]);
			else if (map[i][j] == ' ')
				printf("%c", ' ');
			else
				printf("\e[41m%c\e[0m", map[i][j]);
		}
		printf("\n");
		j = -1;
	}
}

void	init_map(t_data *data, char **argv)
{
	data->map.charmatrix = fetch_map_array(argv);
	map_validation(fetch_map_array(argv));
}
