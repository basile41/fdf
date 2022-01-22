/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:55:55 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/22 19:03:49 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_alloc_map_px(t_map *map)
{
	int	i;

	map->px = malloc(map->nb_line * sizeof(t_px *));
	map->px2 = malloc(map->nb_line * sizeof(t_px *));
	i = 0;
	while (i < map->nb_line)
	{
		map->px[i] = malloc(map->nb_col * sizeof(t_px));
		map->px2[i] = malloc(map->nb_col * sizeof(t_px));
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
	ft_draw_line(&map->px[1][0], &map->px[1][1], data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

void	ft_create_map(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	map->height = WINDOW_WIDTH / (map->nb_line + map->nb_col);
	map->width = map->height * 2;
	ft_alloc_map_px(map);
	x = (WINDOW_WIDTH - (map->nb_col - map->nb_line) * map->height) / 2;
	y = 50;
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			map->px[i][j].x = x + (j - i) * (map->width / 2);
			map->px[i][j].y = y + (i + j) * (map->height / 2)
				- map->p[i][j].height * 5;
			j++;
		}
		ft_memcpy(map->px2[i], map->px[i], j * sizeof(t_px));
		i++;
	}
}
