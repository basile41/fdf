/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:33:32 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/15 16:44:44 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../includes/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
}t_win;

typedef struct s_px
{
	int	x;
	int	y;
}t_px;

typedef struct s_point
{
	int				high;
	unsigned int	color;
}t_point;

typedef struct s_map
{
	int		x_size;
	int		y_size;
	t_point	**point;
}t_map;

void	ft_draw_line(t_px px1, t_px px2, t_win *win);

t_point	**ft_parsing(const char *pathname);

#endif