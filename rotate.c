/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:08:03 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 11:07:37 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*temp;
	t_list	*first;

	if (list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	temp = ft_lstlast(*list);
	temp->next = first;
	*list = (*list)->next;
	first->next = NULL;
}

void	rotate_a(t_list **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rotate_b(t_list **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rotate_rr(t_list **a, t_list **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
