/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:17:59 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 16:38:45 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_bytes(int fd, char *savebytes);
char	*ft_read_line(char *str);
char	*ft_save_remainbytes(char *totbytes);

char	*ft_strchar(char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_isline(char *s);
char	*ft_strgjoin(char *s1, char *s2);

#endif