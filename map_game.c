/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:54:58 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 16:02:28 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_image(t_map *map_ptr, int w, int h)
{
	void	*mlx;
	void	*mlx_win;

	mlx = map_ptr -> mlx_ptr.mlx;
	mlx_win = map_ptr -> mlx_ptr.mlx_win;
	if (map_ptr -> player_win == 1)
	{
		mlx_put_image_to_window(mlx, mlx_win, map_ptr->img_tom_win.img,
			w * map_ptr->img_tom.width, h * map_ptr->img_tom.height);
		exit_success(map_ptr);
	}
	else if (map_ptr -> player_direction == 0)
	{
		mlx_put_image_to_window(mlx, mlx_win, map_ptr->img_tom.img,
			w * map_ptr->img_tom.width, h * map_ptr->img_tom.height);
	}
	else
		mlx_put_image_to_window(mlx, mlx_win, map_ptr->img_tom_left.img,
			w * map_ptr->img_tom.width, h * map_ptr->img_tom.height);
}

void	put_image_in_map(t_map *map_ptr, char ch, int w, int h)
{
	void	*mlx;
	void	*mlx_win;

	mlx = map_ptr -> mlx_ptr.mlx;
	mlx_win = map_ptr -> mlx_ptr.mlx_win;
	if (ch == '1')
		mlx_put_image_to_window(mlx, mlx_win, map_ptr->img_brick.img,
			w * map_ptr->img_brick.width, h * map_ptr->img_brick.height);
	else if (ch == 'C')
		mlx_put_image_to_window(mlx, mlx_win, map_ptr->img_jerry.img,
			w * map_ptr->img_jerry.width, h * map_ptr->img_jerry.height);
	else if (ch == 'P')
		put_player_image(map_ptr, w, h);
	else if (ch == '0')
		mlx_put_image_to_window(mlx, mlx_win, map_ptr ->img_floor.img,
			w * map_ptr ->img_floor.width, h * map_ptr ->img_floor.height);
	else if (ch == 'E')
		mlx_put_image_to_window(mlx, mlx_win, map_ptr->img_house.img,
			w * map_ptr->img_house.width, h * map_ptr->img_house.height);
}

void	create_game(t_map *map_ptr)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
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
			}
			put_image_in_map(map_ptr, line[y], y, x);
			y++;
		}
		x++;
	}
}
