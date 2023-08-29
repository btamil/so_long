/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:45 by tponnusa          #+#    #+#             */
/*   Updated: 2022/11/21 11:59:04 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	if (!s || !f)
		return (0);
	s1 = ft_strdup(s);
	if (!s1)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s1[i] = f(i, s1[i]);
		i++;
	}
	return (s1);
}
