/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:42:22 by tponnusa          #+#    #+#             */
/*   Updated: 2022/11/29 18:01:53 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp -> next = node;
}
