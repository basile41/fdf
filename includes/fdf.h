/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:33:32 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/11 16:33:51 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
}t_win;

typedef struct s_px
{
	int	x;
	int	y;
}t_px;

void	ft_draw_line(t_px px1, t_px px2, t_win *win);

#endif