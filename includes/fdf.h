/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:33:32 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/20 21:13:41 by bregneau         ###   ########.fr       */
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

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1600
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 900
# endif

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
	int				height;
	unsigned int	color;
}t_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		nb_line;
	int		nb_col;
	t_point	**p;
	t_px	**px;
	int		width;
	int		height;
}t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}	t_data;

void	ft_draw_line(t_px *px1, t_px *px2, t_data *data);

void	ft_parsing(const char *pathname, t_map *map);
void	*ft_puterror(t_map *map, char *msg);
void	ft_destroy_map(t_map *map);
void	ft_init(int x, int y, t_data *data);
void	ft_img_pix_put(t_img *img, int x, int y, int color);
void	ft_img_create(int x, int y, t_data *data);
void	ft_create_map(t_map *map);
void	ft_draw_map(t_data *data, t_map *map);

#endif