/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:36:11 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/23 11:56:10 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_map *map_ptr)
{
	if (map_ptr -> img_tom.img)
		mlx_destroy_image(map_ptr -> mlx_ptr.mlx, map_ptr -> img_tom.img);
	if (map_ptr -> img_jerry.img)
		mlx_destroy_image(map_ptr -> mlx_ptr.mlx, map_ptr -> img_jerry.img);
	if (map_ptr -> img_brick.img)
		mlx_destroy_image(map_ptr -> mlx_ptr.mlx, map_ptr -> img_brick.img);
	if (map_ptr -> img_house.img)
		mlx_destroy_image(map_ptr -> mlx_ptr.mlx, map_ptr -> img_house.img);
	if (map_ptr -> img_floor.img)
		mlx_destroy_image(map_ptr -> mlx_ptr.mlx, map_ptr -> img_floor.img);
	if (map_ptr -> img_tom_left.img)
		mlx_destroy_image(map_ptr -> mlx_ptr.mlx, map_ptr -> img_tom_left.img);
	if (map_ptr -> img_tom_win.img)
		mlx_destroy_image(map_ptr -> mlx_ptr.mlx, map_ptr -> img_tom_win.img);
}

void	free_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst -> next;
		free(lst -> content);
		free(lst);
		lst = tmp;
	}
	free(lst);
}

void	free_memory(t_map *map_ptr)
{
	free_list(map_ptr -> map_data);
	free_images(map_ptr);
	mlx_destroy_window(map_ptr -> mlx_ptr.mlx, map_ptr -> mlx_ptr.mlx_win);
	free(map_ptr);
}

void	free_array(void **arr, int i)
{
	while (i >= 0)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i--;
	}
	free(arr);
}
