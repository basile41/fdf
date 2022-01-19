/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:36:07 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/19 16:43:33 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_img_create(t_data *data)
{
	t_img	*img;

	img = &data->img;
	img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, img->bpp, 
			img->line_len, img->endian);
	printf("bpp = %d\nline_len= %d, endian = %d", 
		img->bpp, img->line_len, img->endian);
}

void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
