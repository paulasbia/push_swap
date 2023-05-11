/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:30:55 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/11 09:42:33 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    push(t_list **list_1, t_list **list_2)
{
    t_list  *temp;

    if (list_2 == NULL)
        return;
    temp = *list_2;
    *list_2 = (*list_2)->next;
    temp->next = *list_1;
    *list_1 = temp;
}

void    push_a(t_list **a, t_list **b)
{
    ft_printf("pa\n");
    push(a, b);
}

void    push_b(t_list **b, t_list **a)
{
    ft_printf("pb\n");
    push(b, a);
}
