/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:21:59 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 16:38:42 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchar(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && (*s != (unsigned char)c))
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

int	ft_isline(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strgjoin(char *s1, char *s2)
{
	int		i;
	size_t	j;
	char	*new;

	if (s1 == NULL)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
