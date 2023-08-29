/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:24:05 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/21 14:29:00 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *map_ptr)
{
	free_memory(map_ptr);
	exit(EXIT_FAILURE);
	return (0);
}

int	handle_keypress(int key_sym, t_map *map_ptr)
{
	if (key_sym == KEY_ESC)
	{
		close_window(map_ptr);
	}
	if (key_sym == KEY_UP_W || key_sym == KEY_UP)
	{
		play_game(map_ptr, map_ptr -> player.x - 1, map_ptr -> player.y, 0);
	}
	else if (key_sym == KEY_LEFT_A || key_sym == KEY_LEFT)
	{
		play_game(map_ptr, map_ptr -> player.x, map_ptr -> player.y - 1, 1);
	}
	else if (key_sym == KEY_DOWN_S || key_sym == KEY_DOWN)
	{
		play_game(map_ptr, map_ptr -> player.x + 1, map_ptr -> player.y, 0);
	}
	else if (key_sym == KEY_RIGHT_D || key_sym == KEY_RIGHT)
	{
		play_game(map_ptr, map_ptr -> player.x, map_ptr -> player.y + 1, 0);
	}
	return (0);
}

/* Height and width is multipied by 30
 * Because Image is created with 30 x 30 
*/

void	create_window(t_map *map_ptr)
{
	int	width_times30;
	int	height_times30;

	width_times30 = map_ptr -> cols * 30;
	height_times30 = map_ptr -> rows * 30;
	map_ptr -> mlx_ptr.mlx = mlx_init();
	if (map_ptr -> mlx_ptr.mlx == NULL)
		exit_error_game(1, map_ptr);
	map_ptr -> mlx_ptr.mlx_win = mlx_new_window(map_ptr -> mlx_ptr.mlx,
			width_times30, height_times30, "So_long");
	if (map_ptr -> mlx_ptr.mlx_win == NULL)
	{
		free(map_ptr -> mlx_ptr.mlx);
		exit_error_game(2, map_ptr);
	}
	initialize_images(map_ptr);
	create_game(map_ptr);
	mlx_hook(map_ptr -> mlx_ptr.mlx_win, ON_DESTROY, 1L << 0,
		close_window, map_ptr);
	mlx_key_hook(map_ptr -> mlx_ptr.mlx_win, handle_keypress, map_ptr);
	mlx_loop(map_ptr ->mlx_ptr.mlx);
}

void	read_save_map(int fd, t_map *map_ptr)
{
	char	*line;
	t_list	*tmp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_lstnew(line);
		if (!tmp)
			exit_error_map(1, map_ptr);
		ft_lstadd_back(&map_ptr->map_data, tmp);
	}
}

int	main(int ac, char **av)
{
	int		file_des;
	char	*file;
	t_map	*map_ptr;

	if (ac != 2)
		exit_error(1);
	file = ft_strrchr(av[1], '.');
	if (file == NULL || ft_strncmp(file, ".ber", 4))
		exit_error(2);
	file_des = open(av[1], O_RDONLY);
	if (file_des < 0)
	{
		ft_putstr_fd("Error\nFile doesn't exists.", 2);
		exit(EXIT_FAILURE);
	}
	map_ptr = malloc(sizeof(t_map));
	if (!map_ptr)
		exit_error(3);
	initialize_map(map_ptr);
	read_save_map(file_des, map_ptr);
	close(file_des);
	validate_map_data(map_ptr);
	create_window(map_ptr);
	free_memory(map_ptr);
	return (EXIT_SUCCESS);
}
