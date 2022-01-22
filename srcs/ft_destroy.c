/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:28:46 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/22 20:31:18 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_destroy_pixels(t_map *map, t_px **px)
{
	int	i;

	i = 0;
	if (px)
	{
		while (i < map->nb_line)
		{
			free(px[i]);
			px[i] = NULL;
			i++;
		}
		free(px);
	}
}

void	ft_destroy_points(t_map *map, t_point **p)
{
	int	i;

	i = 0;
	if (p)
	{
		while (i < map->nb_line)
		{
			free(p[i]);
			p[i] = NULL;
			i++;
		}
		free(p);
	}
}

void	ft_destroy_map(t_map *map)
{
	if (map)
	{
		ft_destroy_pixels(map, map->px);
		map->px = NULL;
		ft_destroy_pixels(map, map->px2);
		map->px2 = NULL;
		ft_destroy_points(map, map->p);
		map->p = NULL;
	}
}

void	ft_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	ft_destroy_map(&data->map);
}

void	ft_exit(t_data *data, int status)
{
	ft_destroy(data);
	exit(status);
}