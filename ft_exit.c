/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:28:23 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/22 20:07:47 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(int err_no)
{
	if (err_no == 1)
		ft_putstr_fd("Error\nProgram takes one argument as a file with .ber", 2);
	else if (err_no == 2)
		ft_putstr_fd("Error\nInput Map file must have extension with .ber ", 2);
	else if (err_no == 3)
		ft_putstr_fd("Error\nIn allocating memory.", 2);
	else if (err_no == 4)
		ft_putstr_fd("Error\nNo data available", 2);
	exit(EXIT_FAILURE);
}

void	exit_error_map(int err_no, t_map *map_ptr)
{
	if (err_no == 1)
		ft_putstr_fd("Error\nIn allocating memory.", 2);
	else if (err_no == 2)
		ft_putstr_fd("Error\nNo data available", 2);
	else if (err_no == 3)
		ft_putstr_fd("Error\nMap should be Surrounded by WALL(1's)", 2);
	else if (err_no == 4)
		ft_putstr_fd("Error\nMap Column's are not same", 2);
	else if (err_no == 5)
		ft_putstr_fd("Error\nMap should be in Rectangular Format", 2);
	else if (err_no == 6)
		ft_putstr_fd("Error\nMap must have one C,E & P as Game characters", 2);
	else if (err_no == 7)
		ft_putstr_fd("Error\nMap contains Game characters more than once", 2);
	else if (err_no == 8)
		ft_putstr_fd("Error\nMap must contain Game characters as 1|0|C|E|P", 2);
	else if (err_no == 9)
		ft_putstr_fd("Error\nTom does not have path to reach Home", 2);
	free_list(map_ptr -> map_data);
	free(map_ptr);
	exit(EXIT_FAILURE);
}

void	exit_error_game(int err_no, t_map *map_ptr)
{
	if (err_no == 1)
		ft_putstr_fd("Error\nIn Getting Graphics Object.", 2);
	else if (err_no == 2)
		ft_putstr_fd("Error\nIn Getting Window Graphic Object.", 2);
	else if (err_no == 3)
		ft_putstr_fd("Error\nIn Getting an Image from library", 2);
	if (err_no == 1 || err_no == 2)
	{
		free_list(map_ptr -> map_data);
		free(map_ptr);
	}
	else
		free_memory(map_ptr);
	exit(EXIT_FAILURE);
}

void	exit_success(t_map *map_ptr)
{
	ft_putstr_fd("   \n\
							   ____  \n\
				   ||   ||   //    \\   ||     ||    ||      || ||   ||\\   ||      \n\
				   ||   ||  ||     ||   ||     ||    ||      || ||   || \\  ||      \n\
				   ||   ||  ||     ||   ||     ||    || //\\ || ||   ||	 \\	||      \n\
					 ||      \\____//    \\___//     ||//  \\|| || 	 ||   \\||.     \n\
					 ||                                                             \n\
					   \n", 1);
	free_memory(map_ptr);
	exit(EXIT_SUCCESS);
}
