/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:56:48 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 18:14:19 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map_ptr)
{
	map_ptr -> map_data = NULL;
	map_ptr -> cols = 0;
	map_ptr -> rows = 0;
	map_ptr -> total_jerry = 0;
	map_ptr -> visited = 0;
	map_ptr -> player.x = 0;
	map_ptr -> player.y = 0;
	map_ptr -> player_direction = 0;
	map_ptr -> player_win = 0;
	map_ptr -> path_exist = 0;
	map_ptr -> jerry_count = 0;
	map_ptr -> moves = 0;
}

/** Getting image pointer from libaray one time to avoid doing it in loop 
 *  while rendering map
**/

t_image	get_image(t_map *map_ptr, char *xpm_file)
{
	t_image	image;
	void	*mlx;

	mlx = map_ptr -> mlx_ptr.mlx;
	image.img = mlx_xpm_file_to_image(mlx, xpm_file,
			&image.height, &image.width);
	if (image.img == NULL)
		exit_error_game(3, map_ptr);
	return (image);
}

void	initialize_images(t_map *map_ptr)
{
	map_ptr -> img_tom = get_image(map_ptr, PLAYER_XPM);
	map_ptr -> img_jerry = get_image(map_ptr, COLLECTIBLE_XPM);
	map_ptr -> img_brick = get_image(map_ptr, WALL_XPM);
	map_ptr -> img_house = get_image(map_ptr, EXIT_XPM);
	map_ptr -> img_floor = get_image(map_ptr, FLOOR_XPM);
	map_ptr -> img_tom_left = get_image(map_ptr, PLAYER_LEFT_XPM);
	map_ptr -> img_tom_win = get_image(map_ptr, PLAYER_WIN_XPM);
}
