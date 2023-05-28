/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:37:36 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/28 10:43:46 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		swap_a(stack_a);
	if (ft_lstsize(*stack_a) == 3)
		rule_3(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_find_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while (get_content(*stack_a) != ft_find_min(*stack_a))
				rotate_a(stack_a);
		}
		else
		{
			while (get_content(*stack_a) != ft_find_min(*stack_a))
				rev_rot_a(stack_a);
		}
	}
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

t_list	*ft_sort_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && ft_checksorted(*stack_a) == 0)
		push_b(&stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && ft_checksorted(*stack_a) == 0)
		push_b(&stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && ft_checksorted(*stack_a) == 0)
		ft_sort_b_till_3(stack_a, &stack_b);
	if (ft_checksorted(*stack_a) == 0)
		rule_3(stack_a);
	return (stack_b);
}

// This function sort and push stacks until 3 members left behind.
void	ft_sort_b_till_3(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*temp;

	while (ft_lstsize(*stack_a) > 3 && ft_checksorted(*stack_a) == 0)
	{
		temp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rarb(stack_a, stack_b, get_content(temp), 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rrarrb(stack_a, stack_b, get_content(temp), 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rarrb(stack_a, stack_b, get_content(temp), 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rrarb(stack_a, stack_b, get_content(temp), 'a');
			else
				temp = temp->next;
		}
	}
}

t_list	**ft_sort_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*temp;

	while (*stack_b != 0)
	{
		temp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rarb(stack_a, stack_b, get_content(temp), 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b,
					get_content(temp)))
				i = ft_apply_rarrb(stack_a, stack_b, get_content(temp), 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b,
					get_content(temp)))
				i = ft_apply_rrarrb(stack_a, stack_b, get_content(temp), 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b,
					get_content(temp)))
				i = ft_apply_rrarb(stack_a, stack_b, get_content(temp), 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}
