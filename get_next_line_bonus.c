/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:16:24 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/11 14:41:55 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_checknl(char **str, char *afternl, char **buff)
{
	char	*buffnl;
	size_t	buffnl_len;

	buffnl = ft_strchr(*buff, '\n');
	buffnl_len = ft_strlen(buffnl);
	if (buffnl)
	{
		ft_strlcpy(afternl, buffnl + 1, buffnl_len - 1);
		*str = ft_strndup(NULL, *buff, ft_strlen(*buff) - buffnl_len + 1);
		return (*str);
	}
	return (NULL);
}

char	*ft_exit(char *str, char **temp)
{
	free(*temp);
	return (str);
}

int	ft_read(int fd, char *buff, int len)
{
	int	j;

	j = read(fd, buff, len);
	buff[j] = '\0';
	return (j);
}

void	ft_update(int *j, int fd, char **temp)
{
	char	buff[BUFFER_SIZE + 1];

	*j = ft_read(fd, buff, BUFFER_SIZE);
	if (*j > 0)
		*temp = ft_strjoin(*temp, buff);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	afternl[1024][BUFFER_SIZE + 1];
	char		*str;
	int			j;

	str = NULL;
	temp = NULL;
	if (fd < 0)
		return (NULL);
	if (*afternl[fd])
	{
		temp = ft_strjoin(temp, afternl[fd]);
		if (ft_checknl(&str, afternl[fd], &temp))
			return (ft_exit(str, &temp));
		ft_strlcpy(afternl[fd], "\0", 1);
	}
	j = BUFFER_SIZE;
	while (j > 0)
	{
		ft_update(&j, fd, &temp);
		if (ft_checknl(&str, afternl[fd], &temp))
			return (ft_exit(str, &temp));
	}
	return (temp);
}
