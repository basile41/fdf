/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:55:55 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/24 20:48:08 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_alloc_map_px(t_map *map, t_data *data)
{
	int	i;

	map->px = ft_calloc(map->nb_line, sizeof(t_px *));
	map->px_z = ft_calloc(map->nb_line, sizeof(t_px *));
	if (!map->px || !map->px_z)
		ft_exit(data, EXIT_FAILURE);
	i = 0;
	while (i < map->nb_line)
	{
		map->px[i] = malloc(map->nb_col * sizeof(t_px));
		map->px_z[i] = malloc(map->nb_col * sizeof(t_px));
		if (!map->px[i] || !map->px_z[i])
			ft_exit(data, EXIT_FAILURE);
		i++;
	}
}

void	ft_draw_map(t_data *data, t_map *map)
{
	int	i;
	int	j;

	ft_clear(data);
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			if (i)
				ft_draw_line(&map->px_z[i][j], &map->px_z[i - 1][j], data);
			if (j)
				ft_draw_line(&map->px_z[i][j], &map->px_z[i][j - 1], data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	ft_hud(data);
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
			map->px[i][j].y = map->start.y + (i + j) * (map->height / 2);
			j++;
		}
		i++;
	}
	ft_add_z(map, map->px);
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
	map->origin.x = map->start.x + (map->nb_col - map->nb_line)
		* (map->width / 4);
	map->origin.y = 50 + (map->nb_line + map->nb_col) * (map->height / 4);
	map->z = 1;
	map->zoom = 1;
	ft_fill_map(map);
}
