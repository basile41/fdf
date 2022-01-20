/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:36:07 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/20 12:12:08 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_img_create(int x, int y, t_data *data)
{
	t_img	*img;

	img = &data->img;
	img->img_ptr = mlx_new_image(data->mlx_ptr, x, y);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, 
			&img->line_len, &img->endian);
}

void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
