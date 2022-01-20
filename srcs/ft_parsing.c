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
	point->height = ft_atoi(str);
	point->color = 0;
	str = ft_strchr(str, ',');
	if (str && ft_strlen(str) == 11)
		point->color = ft_atoi_base(str + 3, "123456789ABCDEF");
}

int	ft_parse_line(int fd, t_point **p)
{
	char	*line;
	char	**strs;
	int		i;
	int		size;
	t_point	*pl;

	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	strs = ft_split(line, ' ');
	free(line);
	size = ft_strs_count(strs);
	pl = malloc(size * sizeof(*pl));
	i = -1;
	while (++i < size)
		ft_parse_point(pl + i, strs[i]);
	ft_free_strs(strs);
	*p = pl;
	return (i);
}

t_map	*ft_parse(int fd, t_map *map)
{
	int		i;
	t_point	**p;
	int		nb_col;

	p = ft_calloc(1, sizeof(*p));
	i = 0;
	nb_col = ft_parse_line(fd, p);
	map->nb_col = nb_col;
	while (nb_col && nb_col == map->nb_col)
	{
		i = ++map->nb_line;
		p = ft_realloc(p, i * sizeof(*p), (i + 1) * sizeof(*p));
		if (p == NULL)
			return (ft_puterror(map, "Alloc error"));
		map->p = p;
		nb_col = ft_parse_line(fd, p + i);
	}
	if (nb_col && nb_col < map->nb_col)
		return (ft_puterror(map, "Found wrong line length. Exiting."));
	return (map);
}

void	ft_parsing(const char *pathname, t_map *map)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	ft_parse(fd, map);
}
