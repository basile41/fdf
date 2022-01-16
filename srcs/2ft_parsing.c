/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:53:35 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/16 14:18:05 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_strs_count(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return (0);
	while (strs[i])
		i++;
	return (i);
}

void	ft_parse_point(t_point *point, char *str)
{
	point->high = ft_atoi(str);
	str = ft_strchr(str, ',');
	if (str && ft_strlen(str) == 11)
		point->color = ft_atoi_base(str + 3, "123456789ABCDEF");
}

int	ft_parse_line(int fd, t_point **p_line)
{
	char	*line;
	char	**strs;
	int		i;
	int		size;

	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	strs = ft_split(line, ' ');
	free(line);
	size = ft_strs_count(strs);
	*p_line = malloc(size * sizeof(**p_line));
	i = 0;
	while (i < size)
		ft_parse_point(p_line[i], strs[i++]);
	ft_free_strs(strs);
	return (size);
}

t_map	*ft_parse(int fd, t_map *map)
{
	int		i;
	t_point	**p;

	p = ft_calloc(1, sizeof(*p));
	if (p == NULL)
		return (NULL);
	i = 0;
	map->nb_col = ft_parse_line(fd, p);
	while (p && p[i])
	{
		p = ft_realloc(p, i * sizeof(*p), (i + 1) * sizeof(*p));
		if (p == NULL)
			return (ft_error(map, "Alloc error"));
		map->p = p;
		if (ft_parse_line(fd, p) < map->nb_col)
			return (ft_error(map, "Found wrong line length. Exiting."));
		i++;
		map->nb_line++;
	}
	return (map);
}

t_map	*ft_parsing(const char *pathname, t_map *map)
{
	int	fd;
	int	i;
	int	size;

	fd = open(pathname, O_RDONLY);
	map = ft_calloc(1, sizeof(*map));
	if (map == NULL)
		return (NULL);
	i = 0;
	ft_parse(fd, map);
	// map->nb_col = ft_parse_line(fd, map->p);
	// while (map->p[i])
	// {
	// 	size = ft_parse_line(fd, map->p + i);
	// 	if (size < map->nb_col)
	// 	{
	// 		ft_putstr("incorrect map\n");
	// 	}
	}
}
