/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:32:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/23 17:36:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_bzero(&data, sizeof(data));
		ft_init(WINDOW_WIDTH, WINDOW_HEIGHT, &data);
		if (ft_parsing(av[1], &data.map) == 0)
			ft_exit(&data, EXIT_FAILURE);
		ft_create_map(&data.map, &data);
		ft_draw_map(&data, &data.map);
		mlx_loop(data.mlx_ptr);
		ft_destroy(&data);
	}
	else
		ft_putendl("Incorrect number of arguments");
}
