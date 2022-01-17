/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:33:32 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/17 17:25:22 by bregneau         ###   ########.fr       */
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
	int		nb_line;
	int		nb_col;
	t_point	**p;
}t_map;

void	ft_draw_line(t_px px1, t_px px2, t_win *win);

t_map	*ft_parsing(const char *pathname, t_map *map);
void	*ft_puterror(t_map *map, char *msg);
void	ft_destroy_map(t_map *map);

#endif