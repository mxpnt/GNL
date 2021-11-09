/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:16:24 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/09 16:06:02 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_check_line(char	*str)
{
	static int	i = 0;

	while (str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char			*temp;
	static char		buff[BUFFER_SIZE + 1] = {'\0'};
	//char		buff[BUFFER_SIZE + 1];
	char			*str;
	int				i;
	int				j;
	
	i = 0;
	temp = NULL;
	str = NULL;
	//dprintf(1,"b=%s=\n",buff);
	if (ft_strchr(buff, '\n') != 0)
	{
		temp = ft_strjoin(temp, ft_strchr(buff, '\n') + 1);
		i = ft_strlen(temp);
	}
	//dprintf(1,"b=%s=\n",temp);
	j = read(fd, buff, BUFFER_SIZE);
	while (j > 0 || (j == 0 && temp))
	{
		//dprintf(1, "1");
		buff[j] = '\0';
		temp = ft_strjoin(temp, buff);
		//dprintf(1, "2");
		i += j - ft_strlen(ft_strchr(buff, '\n'));
		if (j == 0 || ft_strchr(buff, '\n') != 0)
		{
			//dprintf(1, "3");
			if (ft_strchr(temp, '\n') != 0)
			{
				//dprintf(1, "nlf\n");
				//dprintf(1, "\ni=%d|j=%d|buff=%s|temp=%s=\n", i, j, buff, temp);
				i++;
			}
			str = ft_strndup(str, temp, i);
			//dprintf(1, "str=%s=\n", str);
			free(temp);
			return (str);
		}
		j = read(fd, buff, BUFFER_SIZE);
	}
	//dprintf(1, "5\n");
	//free(temp);
	return (0);
}
