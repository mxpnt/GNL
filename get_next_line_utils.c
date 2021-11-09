/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:16:44 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/09 15:13:32 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *dst, char *src, int size)
{
	int	i;

	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	size1;
	size_t	size2;
	size_t	i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	dst = malloc((size1 + size2 + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = -1;
	if	(s1)
	{
		while (s1[++i])
			dst[i] = s1[i];
	}
	i = -1;
	if (s2)
	{
		while (s2[++i])
			dst[size1 + i] = s2[i];
	}
	dst[size1 + size2] = '\0';
	if (s1)
		free(s1);
	return (dst);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
