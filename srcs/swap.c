/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:40:54 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/03 10:28:00 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = temp->next->next;
	(*lst)->next = temp;
}

void	swap_a(t_list **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	swap_b(t_list **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	swap_ss(t_list **a, t_list **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
