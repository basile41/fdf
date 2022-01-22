/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:13:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/22 19:27:39 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_add_z(t_map *map)
{
	int	i;
	int	j;

	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			map->px2[i][j].x = map->px[i][j].x;
			map->px2[i][j].y = map->px[i][j].y - map->p[i][j].height * 5;
			j++;
		}
		i++;
	}
}

void	ft_rotation(t_map *map)
{
	
}

void	ft_translation(t_map *map)
{
	
}
