/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 02:48:27 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/07 13:57:51 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (dst);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	size;
	size_t	i;
	char	*dst;

	size = ft_strlen(s1);
	if (size > n)
		size = n;
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
