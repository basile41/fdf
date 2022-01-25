/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:13:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/25 17:29:20 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_add_z(t_map *map, t_px **px)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			map->px_z[i][j].x = px[i][j].x;
			map->px_z[i][j].y = px[i][j].y - map->p[i][j].height * map->z;
			j++;
		}
		i++;
	}
}

void	ft_rotation(t_data *data, t_map *map, double angle)
{
	int	i;
	int	j;
	int	x;
	int	y;

	angle += map->angle;
	map->angle = angle;
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			x = map->px[i][j].x - map->origin.x;
			y = map->px[i][j].y - map->origin.y;
			map->px_z[i][j].x = x * cos(angle) - y * sin(angle) + map->origin.x;
			map->px_z[i][j].y = y * cos(angle) + x * sin(angle) + map->origin.y;
			j++;
		}
		i++;
	}
	ft_add_z(map, map->px_z);
	ft_draw_map(data, map);
}

void	ft_zoom(t_data *data, t_map *map, double s)
{
	int	i;
	int	j;
	int	x;
	int	y;

	map->zoom *= s;
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			x = map->px[i][j].x - map->origin.x;
			y = map->px[i][j].y - map->origin.y;
			map->px_z[i][j].x = x * map->zoom + map->origin.x;
			map->px_z[i][j].y = y * map->zoom + map->origin.y;
			j++;
		}
		i++;
	}
	ft_add_z(map, map->px_z);
	ft_draw_map(data, map);
}

void	ft_move_z(t_data *data, t_map *map, int z)
{
	map->z += z;
	ft_zoom(data, &data->map, 1);
}

void	ft_translation(t_data *data, t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			map->px[i][j].x += x;
			map->px[i][j].y += y;
			j++;
		}
		i++;
	}
	map->origin.x += x;
	map->origin.y += y;
	ft_zoom(data, &data->map, 1);
}
