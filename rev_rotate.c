/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:38:06 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 12:58:28 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_remove_back(t_list **list)
{
    t_list  *last_node;
    t_list  *first_node;

    first_node = *list;
    if (*list == NULL)
        return (NULL);
    if (first_node->next == NULL)
    {
        *list = NULL;
        return (first_node);
    }   
    while (first_node->next->next != 0)
        first_node = (first_node)->next;
    last_node = first_node->next;
    first_node->next = NULL;
    return (last_node);
}

static void	rev_rotate(t_list **list)
{
	t_list	*temp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp = ft_remove_back(list);
	ft_lstadd_front(list, temp);
}

void	rev_rot_a(t_list **a)
{
	ft_printf("rra\n");
	rev_rotate(a);
}

void	rev_rot_b(t_list **b)
{
	ft_printf("rrb\n");
	rev_rotate(b);
}

void	rev_rot_ab(t_list **a, t_list **b)
{
	ft_printf("rrr\n");
	rev_rotate(a);
	rev_rotate(b);
}
