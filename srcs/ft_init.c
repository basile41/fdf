/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:28:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/25 17:29:54 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_hud(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0, 0x00FF00,
		"Fleches : deplacer la map");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 20, 0x00FF00,
		"Molette : zoom");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 400, 0, 0x00FF00,
		"+ : augmenter la hauteur");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 400, 20, 0x00FF00,
		"- : diminuer la hauteur");
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == 69)
		ft_move_z(data, &data->map, 1);
	if (key == 78)
		ft_move_z(data, &data->map, -1);
	if (key == 15)
		ft_rotation(data, &data->map, 0.1);
	if (key == 126)
		ft_translation(data, &data->map, 0, -10);
	if (key == 125)
		ft_translation(data, &data->map, 0, 10);
	if (key == 123)
		ft_translation(data, &data->map, -10, 0);
	if (key == 124)
		ft_translation(data, &data->map, 10, 0);
	if (key == 53)
		ft_exit(data, EXIT_SUCCESS);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
		ft_zoom(data, &data->map, 1.1);
	if (button == 5)
		ft_zoom(data, &data->map, 0.9);
	y = 0;
	x = 0;
	return (0);
}

void	ft_init(int x, int y, t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr)
	{
		data->win_ptr = mlx_new_window(data->mlx_ptr, x, y, "fdf");
		if (data->win_ptr == NULL)
			ft_exit(data, EXIT_FAILURE);
		ft_img_create(x, y, data);
		mlx_key_hook(data->win_ptr, ft_key_hook, data);
		mlx_mouse_hook(data->win_ptr, ft_mouse_hook, data);
	}
}
