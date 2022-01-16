/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:32:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/16 13:03:55 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	affmap(t_map *map)
{
	int	i;
	int	j;

	printf("%i\n", map->nb_line);
	i = -1;
	while (++i < map->nb_line)
	{
		j = -1;
		while (++j < map->nb_col)
		{
			printf("%.2d ", map->p[i][j].high);
		}
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	if (ac == 2)
	{
		map = ft_parsing(av[1], map);
		affmap(map);
	}
}
