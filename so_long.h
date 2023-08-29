/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:05:06 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 18:09:53 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"

# include "./mlx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_UP_W 13
# define KEY_DOWN 125
# define KEY_DOWN_S 1
# define KEY_RIGHT 124
# define KEY_RIGHT_D 2
# define KEY_LEFT 123
# define KEY_LEFT_A 0
# define ON_DESTROY 17

# define PLAYER_XPM "./images/tom.xpm"
# define COLLECTIBLE_XPM "./images/jerry.xpm"
# define WALL_XPM "./images/brick.xpm"
# define EXIT_XPM "./images/house.xpm"
# define FLOOR_XPM "./images/floor.xpm"
# define PLAYER_LEFT_XPM "./images/tom_left.xpm"
# define PLAYER_WIN_XPM "./images/tom_win.xpm"

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_image {
	int		height;
	int		width;
	void	*img;
}	t_image;

typedef struct s_coordinate {
	int	x;
	int	y;
}	t_cell;

typedef struct s_map {
	t_list	*map_data;
	t_mlx	mlx_ptr;
	t_image	img_tom;
	t_image	img_jerry;
	t_image	img_brick;
	t_image	img_floor;
	t_image	img_house;
	t_image	img_tom_left;
	t_image	img_tom_win;
	t_cell	player;
	int		jerry_count;
	int		**visited;
	int		cols;
	int		rows;
	int		total_jerry;
	int		player_direction;
	int		player_win;
	int		path_exist;
	int		moves;
}	t_map;

void	exit_error(int err_no);
void	exit_error_map(int err_no, t_map *map_ptr);
void	free_list(t_list *lst);
void	validate_map_data(t_map *map_ptr);
int		is_wall(char *s, int len);
int		is_strchr(char *s, char ch);
void	create_game(t_map *map_ptr);
void	initialize_images(t_map *ptr);
void	initialize_map(t_map *map_ptr);
void	play_game(t_map *map_ptr, int x, int y, int player_dir);
char	*get_list_at_index(t_list *map_data, int index);
void	update_list(t_list *map_data, char *line, int pos);
void	free_memory(t_map *map_ptr);
void	trim_data_at_begin(t_list **list);
void	trim_data_at_end(t_list **list);
void	exit_error_game(int err_no, t_map *map_ptr);
void	exit_error_map(int err_no, t_map *map_ptr);
void	exit_success(t_map *map_ptr);
int		is_valid_game_characters(t_map *map_ptr);
void	set_player_position(t_map *map_ptr);
int		is_valid_input(char ch);
void	check_valid_path_avilable(t_map *map_ptr);
void	free_array(void **arr, int i);

#endif