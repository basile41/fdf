/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:49:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/16 19:53:21 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*ft_error(t_map *map, char *msg)
{
	ft_putendl(msg);
	ft_destroy(map);
	return (NULL);
}
