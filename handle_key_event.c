/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:32:08 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 18:13:57 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_row(t_map *map_ptr, int new_x, int new_y)
{
	char	*player_current_row;
	char	*player_new_row;
	int		old_x;
	int		old_y;

	old_x = map_ptr -> player.x;
	old_y = map_ptr -> player.y;
	player_current_row = get_list_at_index(map_ptr -> map_data, old_x);
	player_new_row = get_list_at_index(map_ptr -> map_data, new_x);
	if (player_new_row[new_y] == 'C')
			map_ptr -> total_jerry--;
	if (player_new_row[old_y] == '0'
		|| player_new_row[old_y] == 'C')
	{
		player_new_row[new_y] = 'P';
		player_current_row[old_y] = '0';
	}
	else if (player_new_row[new_y] == 'E' && map_ptr -> total_jerry == 0)
		map_ptr -> player_win = 1;
	update_list(map_ptr-> map_data, player_new_row, new_x);
	update_list(map_ptr-> map_data, player_current_row, old_x);
}

void	update_column(t_map *map_ptr, int new_y)
{
	char	*player_current_row;
	int		old_x;
	int		old_y;

	old_x = map_ptr -> player.x;
	old_y = map_ptr -> player.y;
	player_current_row = get_list_at_index(map_ptr -> map_data, old_x);
	if (player_current_row[new_y] == 'C' )
		map_ptr -> total_jerry--;
	if (player_current_row[new_y] == '0'
		|| player_current_row[new_y] == 'C')
	{
		player_current_row[new_y] = 'P';
		player_current_row[old_y] = '0';
	}
	else if (player_current_row[new_y] == 'E' && map_ptr -> total_jerry == 0)
		map_ptr -> player_win = 1;
	update_list(map_ptr-> map_data, player_current_row, old_x);
}

void	play_game(t_map *map_ptr, int new_x, int new_y, int player_dir)
{
	map_ptr -> player_direction = player_dir;
	map_ptr -> moves++;
	if (map_ptr -> player.x != new_x)
		update_row(map_ptr, new_x, new_y);
	else if (map_ptr -> player.y != new_y)
		update_column(map_ptr, new_y);
	mlx_clear_window(map_ptr->mlx_ptr.mlx, map_ptr->mlx_ptr.mlx_win);
	create_game(map_ptr);
	ft_putstr_fd("Player Moves :", 1);
	ft_putnbr_fd(map_ptr -> moves, 1);
	ft_putchar_fd('\n',1);
}
