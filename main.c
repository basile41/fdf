/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:32:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/20 21:13:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_test(t_data *data)
{
	int		i;
	int		j;
	t_map	*map;

	map = &data->map;
	ft_create_map(map);
	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 19)
		{
			ft_img_pix_put(&data->img, map->px[i][j].x, map->px[i][j].y,
				0xFF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_parsing(av[1], &data.map);
		ft_init(WINDOW_WIDTH, WINDOW_HEIGHT, &data);
		ft_create_map(&data.map);
		ft_draw_map(&data, &data.map);
		// ft_test(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_putendl("Incorrect number of arguments");
}
