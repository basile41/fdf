/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:53:35 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/11 19:53:38 by bregneau         ###   ########.fr       */
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

void	ft_set_point(t_map *point, char *str)
{
	char	*ptr;

	point.high = ft_atoi(str);
	ptr = ft_strchr(str, ',');
	if (ptr && ptr[1] == '0' && ptr[2] == 'x')
		point.color = ft_atoi_base(ptr + 3, "123456789ABCDEF");
	else
		point.color = 0xFFFFFF;
}

void	ft_parse_line(char **strs, t_map *map_line)
{
	int	size;
	int	i;

	size = ft_strs_count(strs);
	map_line = malloc((size + 1) * sizeof(*map_line));
	if (!map_line)
		return (NULL);
	map_line->high = size;
	while (i++ < size)
		ft_set_point(map_line + i, strs[i]);
}

int	ft_parsing(const char *pathname)
{
	int		fd;
	t_map	**map;
	int		i;

	fd = open(pathname, O_RDONLY);
	while (1)
	{
		map = ft_realloc();
		ft_parse_line(ft_split(get_next_line(fd), ' '), map);
	}
	close(fd);
}
