/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:55:55 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/20 22:25:58 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_alloc_map_px(t_map *map)
{
	int	i;

	map->px = malloc(map->nb_line * sizeof(t_px *));
	i = 0;
	while (i < map->nb_line)
	{
		map->px[i] = malloc(map->nb_col * sizeof(t_px));
		i++;
	}
}

void	ft_draw_map(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->nb_line)
	{
		j = 1;
		while (j < map->nb_col)
		{
			// ft_draw_line(&map->px[i][j], &map->px[i - 1][j], data);
			ft_draw_line(&map->px[i][j], &map->px[i][j - 1], data);
			
			printf("i = %d\tj = %d   \t", i, j);
			printf("x = %d \t", map->px[i][j].x);
			printf("y = %d\n", map->px[i][j].y);
			j++;
		}
		i++;
	}
	ft_draw_line(&map->px[1][0], &map->px[1][1], data);
	// printf("%d\n", 800 + (0 - 0) * (40 / 2));
	// printf("%d , %d\n",map->px[0][0].x, map->px[0][0].y);
	// printf("%d , %d\n",map->px[10][9].x, map->px[10][9].y);
	// ft_draw_line(&map->px[0][18], &map->px[10][18], data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}

void	ft_create_map(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	map->width = 40;
	map->height = 20;
	ft_alloc_map_px(map);
	x = 800;
	y = 100;
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			printf("i = %d\tj = %d   \t", i, j);
			printf("x = %d \t", x + (j - i) * (map->width / 2));
			printf("y = %d\n", y + (i + j) * (map->height / 2));
			map->px[i][j].x = x + (j - i) * (map->width / 2);
			map->px[i][j].y = y + (i + j) * (map->height / 2)/* - map->p[i][j].height*/;
			j++;
		}
		i++;
	}
}
