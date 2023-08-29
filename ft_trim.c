/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:48:11 by tponnusa          #+#    #+#             */
/*   Updated: 2023/06/21 14:04:43 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** If input data is valid one, then trim data at the beginning and 
 * end.
*/

void	trim_data_at_begin(t_list **lst)
{
	t_list	*tmp;
	char	*line;

	tmp = (*lst);
	line = NULL;
	while (tmp)
	{
		line = tmp -> content;
		if (line[0] != '\n')
			break ;
		if (line[0] == '\n')
		{
			tmp = (*lst)-> next;
			free((*lst)-> content);
			free(*lst);
			(*lst) = tmp;
		}
		else
			tmp = tmp -> next;
	}
}

void	trim_data_at_end(t_list **lst)
{
	t_list	*tmp_last;
	t_list	*tmp;

	tmp = (*lst);
	tmp_last = NULL;
	while (tmp)
	{
		if (((char *)tmp -> content)[0] != '\n' && tmp -> next
			&& ((char *)tmp -> next -> content)[0] == '\n')
		{
			tmp_last = tmp -> next;
			tmp -> next = NULL;
			break ;
		}
		tmp = tmp -> next;
	}
	while (tmp_last)
	{
		tmp = tmp_last -> next;
		free(tmp_last -> content);
		free(tmp_last);
		tmp_last = tmp;
	}
}
