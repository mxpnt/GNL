/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:17:05 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/11 15:22:15 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_checknl(char **str, char afternl[BUFFER_SIZE], char **buff);
char	*ft_exit(char *str, char **temp);
int		ft_read(int fd, char *buff, int len);
void	ft_update(int *j, int fd, char **temp);
char	*ft_strndup(char *dst, char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif