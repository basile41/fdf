/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:36:07 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/25 17:29:07 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_clear(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	ft_img_create(WINDOW_WIDTH, WINDOW_HEIGHT, data);
}

void	ft_img_create(size_t x, size_t y, t_data *data)
{
	t_img	*img;

	img = &data->img;
	img->img_ptr = mlx_new_image(data->mlx_ptr, x, y);
	if (img->img_ptr == NULL)
		ft_exit(data, EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
	img->x_size = x;
	img->y_size = y;
}

void	ft_img_pix_put(t_img *img, size_t x, size_t y, int color)
{
	char	*pixel;

	if (x >= img->x_size || y >= img->y_size)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
