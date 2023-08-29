/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:39:05 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/21 17:01:37 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	depth_first_search(t_map *map_ptr, int x, int y)
{
	char	*line;

	line = NULL;
	if (x < 0 || y < 0 || x >= map_ptr -> rows || y >= map_ptr -> cols
		|| map_ptr -> visited[x][y])
		return ;
	line = get_list_at_index(map_ptr->map_data, x);
	if (line == NULL)
		return ;
	if (line[y] == '1')
		return ;
	if (line[y] == 'C')
		map_ptr -> jerry_count++;
	if (line[y] == 'E')
		map_ptr -> path_exist = 1;
	map_ptr -> visited[x][y] = 1;
	depth_first_search(map_ptr, x + 1, y);
	depth_first_search(map_ptr, x - 1, y);
	depth_first_search(map_ptr, x, y + 1);
	depth_first_search(map_ptr, x, y - 1);
}

void	check_valid_path_avilable(t_map *map_ptr)
{
	int	i;

	i = 0;
	map_ptr -> visited = (int **)malloc(map_ptr -> rows * sizeof(int *));
	if (!map_ptr -> visited)
		exit_error_map(1, map_ptr);
	while (i < map_ptr -> rows)
	{
		map_ptr -> visited[i] = ft_calloc(map_ptr -> cols, sizeof(int));
		if (!map_ptr -> visited[i])
		{
			free_array((void **)map_ptr -> visited, i);
			exit_error_map(1, map_ptr);
		}
		i++;
	}
	depth_first_search(map_ptr, map_ptr -> player.x, map_ptr -> player.y);
	if (!(map_ptr -> path_exist)
		|| (map_ptr -> total_jerry != map_ptr -> jerry_count))
	{
		free_array((void **)map_ptr -> visited, i - 1);
		exit_error_map(9, map_ptr);
	}
	free_array((void **)map_ptr -> visited, i - 1);
}
