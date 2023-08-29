/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:26:28 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 16:12:22 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	check_game_characters(t_map *map_ptr)
{
	t_list	*itr;
	char	*line;
	int		c_flag;
	int		e_flag;
	int		p_flag;

	c_flag = 0;
	e_flag = 0;
	p_flag = 0;
	itr = map_ptr -> map_data;
	line = NULL;
	while (itr)
	{
		line = itr -> content;
		c_flag = c_flag + is_strchr(line, 'C');
		e_flag = e_flag + is_strchr(line, 'E');
		p_flag = p_flag + is_strchr(line, 'P');
		itr = itr -> next;
	}
	if (!c_flag || !e_flag || !p_flag)
		exit_error_map(6, map_ptr);
	else if (e_flag > 1 || p_flag > 1)
		exit_error_map(7, map_ptr);
	map_ptr -> total_jerry = c_flag;
}

/**
 * If new line is available after valid data, 
 * It will be removed in trim function.
 * But last line has new line character. So to check column
 * count, decrement the original column size by 1. 
 * as it also has new line character at the end.
*/

void	check_map_rectangular(t_map *map_ptr, int size)
{
	char	*line;
	int		col_y;
	int		row_x;
	char	*tmp_line;
	t_list	*itr;

	col_y = 0;
	row_x = 0;
	line = NULL;
	tmp_line = NULL;
	itr = map_ptr -> map_data;
	while (itr && itr -> next)
	{
		line = itr -> content;
		col_y = ft_strlen(line);
		tmp_line = itr -> next -> content;
		if (tmp_line && tmp_line[col_y - 1] != '\n' && row_x == size - 1)
			col_y --;
		if (col_y != (int)ft_strlen(tmp_line))
			exit_error_map(5, map_ptr);
		itr = itr -> next;
		row_x++;
	}
}

int	check_wall_surrounded(t_map *map_ptr, int size)
{
	t_list	*itr;
	char	*line;
	int		row_x;
	int		col_y;

	row_x = 0;
	col_y = 0;
	itr = map_ptr -> map_data;
	line = NULL;
	while (itr)
	{
		line = itr -> content;
		col_y = ft_strlen(line);
		if (line[col_y - 1] == '\n')
			col_y--;
		if (row_x == 0 && !is_wall(line, col_y))
			exit_error_map(3, map_ptr);
		else if (row_x == (size - 1) && !is_wall(line, col_y))
			exit_error_map(3, map_ptr);
		else if (line[0] != '\n' && (line[0] != '1' || line[col_y - 1] != '1'))
			exit_error_map(3, map_ptr);
		itr = itr -> next;
		row_x++;
	}
	return (col_y);
}

void	validate_map_data(t_map *map_ptr)
{
	if (!map_ptr -> map_data)
		exit_error_map(2, map_ptr);
	trim_data_at_begin(&map_ptr -> map_data);
	trim_data_at_end(&map_ptr -> map_data);
	if (map_ptr->map_data)
	{
		map_ptr->rows = ft_lstsize(map_ptr -> map_data);
		map_ptr->cols = check_wall_surrounded(map_ptr, map_ptr -> rows);
		check_map_rectangular(map_ptr, (map_ptr -> rows - 1));
		if (!is_valid_game_characters(map_ptr))
			exit_error_map(8, map_ptr);
		check_game_characters(map_ptr);
		set_player_position(map_ptr);
		check_valid_path_avilable(map_ptr);
	}
	else
		exit_error_map(2, map_ptr);
}
