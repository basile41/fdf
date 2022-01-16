/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:28:46 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/16 14:32:25 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_destroy_map(t_map *map)
{
	int	i;

	i = -1;
	if (map)
	{
		if (map->p)
		{
			while (++i < map->nb_line)
			{
				free(map->p[i]);
			}
			free(map->p);
		}
		free(map);
	}
}
