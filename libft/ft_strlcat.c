/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:49:35 by tponnusa          #+#    #+#             */
/*   Updated: 2022/11/25 13:20:33 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = 0;
	dlen = 0;
	while (src[slen])
		slen++;
	if (dstsize == 0)
		return (slen);
	while (dlen < dstsize && dst[dlen])
		dlen++;
	if (dstsize <= dlen)
		return (dstsize + slen);
	i = 0;
	while (src[i] && ((dlen + i) < (dstsize - 1)))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
