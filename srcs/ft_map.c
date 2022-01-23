/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:55:55 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/23 17:37:14 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_alloc_map_px(t_map *map, t_data *data)
{
	int	i;

	map->px = ft_calloc(map->nb_line, sizeof(t_px *));
	if (map->px == NULL)
		ft_exit(data, EXIT_FAILURE);
	i = 0;
	while (i < map->nb_line)
	{
		map->px[i] = malloc(map->nb_col * sizeof(t_px));
		if (map->px[i] == NULL)
			ft_exit(data, EXIT_FAILURE);
		i++;
	}
}

void	ft_draw_map(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			if (i)
				ft_draw_line(&map->px[i][j], &map->px[i - 1][j], data);
			if (j)
				ft_draw_line(&map->px[i][j], &map->px[i][j - 1], data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

void	ft_fill_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			map->px[i][j].x = map->start.x + (j - i) * (map->width / 2);
			map->px[i][j].y = map->start.y + (i + j) * (map->height / 2)
				- map->p[i][j].height;
			j++;
		}
		i++;
	}
}

void	ft_create_map(t_map *map, t_data *data)
{
	map->height = (float)WINDOW_WIDTH / (float)(map->nb_line + map->nb_col);
	if (map->height > 20)
		map->height = 20;
	map->width = map->height * 2;
	ft_alloc_map_px(map, data);
	map->start.x = map->height * map->nb_line;
	map->start.y = 50;
	ft_fill_map(map);
}
