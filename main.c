/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:32:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/19 16:59:11 by bregneau         ###   ########.fr       */
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
// 			printf("%.2d ", map->p[i][j].height);
// 			// printf("%.2d ", map->p[i][j].color);
// 		}
// 		printf("\n");
// 	}
// }

int	main(int ac, char **av)
{
	t_map	*map;
	t_data	data;

	map = NULL;
	if (ac == 2)
	{
		map = ft_parsing(av[1], map);
		ft_init(WINDOW_WIDTH, WINDOW_WIDTH, &win);
	}
	else
		ft_putendl("Incorrect number of arguments");
}
