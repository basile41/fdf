/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:38:11 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/20 11:49:15 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_dl_octant_1_5(t_px *px1, t_px *px2, t_px d, t_data *data)
{
	int	e;

	e = 0;
	while (px1->x <= px2->x)
	{
		ft_img_pix_put(&data->img, px1->x, px1->y, 0xFFFFFF);
		px1->x++;
		e += d.y;
		if ((e << 1) >= d.x)
		{
			px1->y++;
			e -= d.x;
		}
	}
}

void	ft_dl_octant_8_4(t_px *px1, t_px *px2, t_px d, t_data *data)
{
	int	e;

	e = 0;
	while (px1->x <= px2->x)
	{
		ft_img_pix_put(&data->img, px1->x, px1->y, 0xFFFFFF);
		px1->x++;
		e += d.y;
		if ((e << 1) <= d.x)
		{
			px1->y--;
			e += d.x;
		}
	}
}

void	ft_dl_octant_2_6(t_px *px1, t_px *px2, t_px d, t_data *data)
{
	int	e;

	e = 0;
	while (px1->y <= px2->y)
	{
		ft_img_pix_put(&data->img, px1->x, px1->y, 0xFFFFFF);
		px1->y++;
		e += d.x;
		if ((e << 1) >= d.y)
		{
			px1->x++;
			e -= d.y;
		}
	}
}

void	ft_dl_octant_7_3(t_px *px1, t_px *px2, t_px d, t_data *data)
{
	int	e;

	e = 0;
	while (px1->y >= px2->y)
	{
		ft_img_pix_put(&data->img, px1->x, px1->y, 0xFFFFFF);
		px1->y--;
		e += d.x;
		if ((e << 1) >= d.y)
		{
			px1->x++;
			e += d.y;
		}
	}
}

void	ft_draw_line(t_px *px1, t_px *px2, t_data *data)
{
	t_px	d;

	d.x = px2->x - px1->x;
	d.y = px2->y - px1->y;
	if (d.x < 0)
		ft_draw_line(px2, px1, data);
	else
		if (d.y >= 0)
			if (d.x >= d.y)
				ft_dl_octant_1_5(px1, px2, d, data);
	else
		ft_dl_octant_2_6(px1, px2, d, data);
	else
		if (d.x >= -d.y)
			ft_dl_octant_8_4(px1, px2, d, data);
	else
		ft_dl_octant_7_3(px1, px2, d, data);
}

/*void	ft_draw_line(t_px px1, t_px px2, t_data *data)
{
	t_px	d;

	d.x = px2->x - px1->x;
	d.y = px2->y - px1->y;
	if (d.x < 0)
		ft_draw_line(px2, px1, data);
	else
		if (d.y >= 0)
			if (d.x >= d.y)
				ft_dl_octant_1_5(px1, px2, d, data);
			else
				ft_dl_octant_2_6(px1, px2, d, data);
		else
			if (d.x >= -d.y)
				ft_dl_octant_8_4(px1, px2, d, data);
			else
				ft_dl_octant_7_3(px1, px2, d, data);
}*/
