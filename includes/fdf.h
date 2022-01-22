/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:33:32 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/22 21:01:10 by bregneau         ###   ########.fr       */
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
# include <errno.h>  

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1600
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 900
# endif

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
	size_t	x_size;
	size_t	y_size;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		nb_line;
	int		nb_col;
	t_point	**p;
	t_px	**px;
	t_px	**px2;
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

int		ft_parsing(const char *pathname, t_map *map);
int		ft_puterror(char *msg);
void	ft_exit(t_data *data, int status);
void	ft_destroy(t_data *data);
void	ft_destroy_map(t_map *map);
void	ft_init(int x, int y, t_data *data);
void	ft_img_pix_put(t_img *img, size_t x, size_t y, int color);
void	ft_img_create(size_t x, size_t y, t_data *data);
void	ft_create_map(t_map *map);
void	ft_draw_map(t_data *data, t_map *map);

#endif