/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:50:58 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/10 15:59:26 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char type)
{
	t_list	*temp;

	// if (*lst == NULL || (*lst)->next == NULL)
	// 	return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = temp->next->next;
	(*lst)->next = temp;
	if (type == 'a')
		ft_printf("sa\n");
	else if (type == 'b')
		ft_printf("sb\n");
}
