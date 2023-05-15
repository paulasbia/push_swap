/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:37:36 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/15 13:47:58 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2 && get_content(*a) > get_content((*a)->next))
		swap_a(a);
	if (ft_lstsize(*a) == 3)
		rule_3(a);
    if (ft_lstsize(*a) > 3)
        rule_5(a, b);    
}

void	rule_3(t_list **a)
{
	if (get_content(*a) > get_content((*a)->next))
	{
		if (get_content(*a) < get_content((*a)->next->next))
			swap_a(a);
		else if (get_content(*a) > get_content((*a)->next->next)
			&& get_content((*a)->next) < get_content((*a)->next->next))
			rotate_a(a);
		else
		{
			rotate_a(a);
			swap_a(a);
		}
	}
	else if (get_content(*a) < get_content((*a)->next))
	{
		if (get_content(*a) > get_content((*a)->next->next))
			rev_rot_a(a);
		else if (get_content((*a)->next) > get_content((*a)->next->next))
		{
			swap_a(a);
			rotate_a(a);
		}
	}
}

void    rule_5(t_list **a, t_list **b)
{
    while (ft_lstsize(*a) > 3)
    {
        if (get_content(*a) > get_content((*a)->next))
        	rotate_a(a);
    	else if (get_content(*a) < get_content((*a)->next))
    	{
        	push_b(b, a);
    	}
    }
    rule_3(a);
	while ((*b) != NULL)
	{
		if (((*b)->next == NULL) || get_content(*b) > get_content((*b)->next))
			push_a(a, b);
		else
		{
			swap_b(b);
			push_a(a, b);
		}
	}
}