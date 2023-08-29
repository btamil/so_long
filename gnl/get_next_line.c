/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:32:17 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 16:38:43 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_remainbytes(char *totbytes)
{
	int		i;
	int		j;
	char	*sbytes;

	i = ft_isline(totbytes);
	if (!totbytes[i])
	{
		free(totbytes);
		return (NULL);
	}
	sbytes = (char *)malloc((ft_strlen(totbytes) - i) + 1);
	if (!sbytes)
		return (NULL);
	j = 0;
	i++;
	while (totbytes[i])
	{
		sbytes[j] = totbytes[i];
		j++;
		i++;
	}
	sbytes[j] = '\0';
	free(totbytes);
	return (sbytes);
}

char	*ft_read_line(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	s = (char *)malloc(ft_isline(str) + 2);
	if (!s)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read_bytes(int fd, char *savebytes)
{
	char	*buff;
	int		bytesread;

	buff = (char *)malloc(((size_t)BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	bytesread = 1;
	while (bytesread != 0 && !ft_strchar(savebytes, '\n'))
	{
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytesread] = '\0';
		savebytes = ft_strgjoin(savebytes, buff);
	}
	free(buff);
	return (savebytes);
}

char	*get_next_line(int fd)
{
	static char	*savebytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	savebytes = ft_read_bytes(fd, savebytes);
	if (!savebytes)
		return (NULL);
	line = ft_read_line(savebytes);
	savebytes = ft_save_remainbytes(savebytes);
	return (line);
}
