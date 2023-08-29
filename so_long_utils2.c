/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:22:54 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 16:14:34 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_list_at_index(t_list *map_data, int index)
{
	int	i;

	i = 0;
	while (map_data)
	{
		if (i == index)
			return (map_data -> content);
		map_data = map_data -> next;
		i++;
	}
	return (0);
}

void	update_list(t_list *map_data, char *line, int pos)
{
	int	i;

	i = 0;
	while (map_data)
	{
		if (i == pos)
		{
			map_data -> content = line;
			break ;
		}
		map_data = map_data -> next;
		i++;
	}
}

void	set_player_position(t_map *map_ptr)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	line = NULL;
	while (x < map_ptr->rows)
	{
		y = 0;
		line = get_list_at_index(map_ptr->map_data, x);
		while (line[y] != '\n' && y < map_ptr->cols)
		{
			if (line[y] == 'P')
			{
				map_ptr -> player.x = x;
				map_ptr -> player.y = y;
				break ;
			}
			y++;
		}
		x++;
	}
}
