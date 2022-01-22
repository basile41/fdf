/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:28:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/22 20:23:37 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_hook(int key)
{
	if (key == 53)
		exit(0);
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
		mlx_key_hook(data->win_ptr, ft_key_hook, 0);
	}
}

