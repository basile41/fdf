/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:53:35 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/15 16:04:41 by bregneau         ###   ########.fr       */
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

int	ft_parse_line(char *line, t_point **point_line)
{
	int		size;
	int		i;
	char	**strs;

	*point_line = NULL;
	if (line == NULL)
		return (1);
	strs = ft_split(line, ' ');
	free(line);
	size = ft_strs_count(strs);
	*point_line = malloc((size) * sizeof(**point_line));
	i = 0;
	while (i < size)
	{
		ft_set_point(*point_line + i, strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
	return (1);
}

t_point	**ft_parsing(const char *pathname)
{
	int		fd;
	int		i;
	t_point	**point;

	i = 0;
	fd = open(pathname, O_RDONLY);
	point = NULL;
	while (42)
	{
		point = ft_realloc(point, i * sizeof(point), (i + 1) * sizeof(point));
		if (!point)
			return (0);
		if (!ft_parse_line(get_next_line(fd), point + i))
			return (0);
		if (point[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (point);
}
