/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:53:35 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/16 18:37:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_strs_count(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_set_point(t_point *point, char *str)
{
	char	*ptr;

	point->high = ft_atoi(str);
	ptr = ft_strchr(str, ',');
	if (ptr && ptr[1] == '0' && ptr[2] == 'x')
		point->color = ft_atoi_base(ptr + 3, "123456789ABCDEF");
	else
		point->color = 0xFFFFFF;
}

int	ft_parse_line(char *line, t_point **p_line)
{
	int		size;
	int		i;
	char	**strs;

	*p_line = NULL;
	if (line == NULL)
		return (0);
	strs = ft_split(line, ' ');
	free(line);
	size = ft_strs_count(strs);
	*p_line = malloc((size) * sizeof(**p_line));
	if (*p_line == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		ft_set_point(*p_line + i, strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
	return (i);
}

int	ft_parsing_loop(t_map *map, int fd)
{
	int	i;
	int	size;

	i = 0;
	while (42)
	{
		map->p = ft_realloc(map->p, i * sizeof(*map->p),
				(i + 1) * sizeof(*map->p));
		if (!map->p)
			return (free(map), 0);
		size = ft_parse_line(get_next_line(fd), map->p + i);
		if (i == 0)
			map->nb_col = size;
		if (size == -1)
			return ((free(map->p), free(map)), 0);
		if (map->p[i] == 0)
			break ;
		i++;
	}
	map->nb_line = i;
	return (1);
}

t_map	*ft_parsing(const char *pathname, t_map *map)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(pathname, O_RDONLY);
	map = malloc(sizeof(*map));
	if (!ft_parsing_loop(map, fd))
		return (NULL);
	close(fd);
	return (map);
}
