/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:14 by tponnusa          #+#    #+#             */
/*   Updated: 2022/11/29 16:40:49 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_present_in_set(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
	i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tstr;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_present_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while ((start < end) && ft_present_in_set(s1[end], set))
		end--;
	len = (end - start) + 1;
	tstr = malloc(len + 1);
	if (!tstr)
		return (0);
	i = 0;
	while (start <= end)
		tstr[i++] = s1[start++];
	tstr[i] = '\0';
	return (tstr);
}
