/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:32:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/17 17:38:57 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

// void	affmap(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	printf("%i\n", map->nb_line);
// 	i = -1;
// 	while (++i < map->nb_line)
// 	{
// 		j = -1;
// 		while (++j < map->nb_col)
// 		{
// 			printf("%.2d ", map->p[i][j].high);
// 			// printf("%.2d ", map->p[i][j].color);
// 		}
// 		printf("\n");
// 	}
// }

int	main(int ac, char **av)
{
	t_map	*map;
	t_win	win;

	map = NULL;
	if (ac == 2)
	{
		map = ft_parsing(av[1], map);
		
	}
}
