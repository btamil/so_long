/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:17:08 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/21 12:43:42 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(char *s, int len)
{
	char	c;
	int		i;
	int		ones;

	c = '1';
	i = 0;
	ones = 0;
	while (s[i])
	{
		if (s[i] == c)
			ones++;
		i++;
	}
	if (ones == len)
		return (1);
	return (0);
}

int	is_strchr(char *s, char ch)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ch)
			count++;
		i++;
	}
	return (count);
}

int	is_valid_input(char ch)
{
	if (ch == '1' || ch == '0' || ch == 'P' || ch == 'E' || ch == 'C')
		return (1);
	else
		return (0);
}

int	is_valid_game_characters(t_map *map_ptr)
{
	char	*line;
	int		i;
	t_list	*itr;

	line = NULL;
	i = 0;
	itr = map_ptr -> map_data;
	while (itr)
	{
		line = itr -> content;
		i = 0;
		while (line[i])
		{
			if (line[i] != '\n' && !is_valid_input(line[i]))
				return (0);
			i++;
		}
		itr = itr -> next;
	}
	return (1);
}
