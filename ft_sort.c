/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:37:36 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/24 15:16:55 by pde-souz         ###   ########.fr       */
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
        // rule_5(stack_a, stack_b);
		stack_b = ft_sort_b(stack_a);
	//	printf("stack_b completa\n");
		//print_list(stack_b);
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
//	printf("entrou\n");

	while (ft_lstsize(*stack_a) > 3 && ft_checksorted(*stack_a) == 0)
	{
		temp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		//printf("sorb_3 i eh %d\n", i);
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
	//	printf("i agira vale:%d\n", i);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rarb(stack_a, stack_b, get_content(temp), 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rarrb(stack_a, stack_b, get_content(temp), 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rrarrb(stack_a, stack_b, get_content(temp), 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, get_content(temp)))
				i = ft_apply_rrarb(stack_a, stack_b, get_content(temp), 'b');
			else
				temp = temp->next;
		}
	}
	return(stack_a);
}


// void	rule_5(t_list **a, t_list **b)
// {
// 	while (ft_lstsize(*a) > 3)
// 		push_b(b, a);
// 	rule_3(a);
// 	sort_a(a, b);
// }

// void	sort_a(t_list **a, t_list **b)
// {	
// 	int		temp_b;
// 	t_list	*temp_a;
// 	double	size_a;
// 	int		qts_maiores;
// 	int		n_rotate;
// 	int		signal;

// 	printf("stack a: \n");
// 	print_list(*a);
// 	printf("stack b: \n");
// 	print_list(*b);
// 	while ((*b) != 0)
// 	{
// 		size_a = ft_lstsize(*a);
// 		temp_b = get_content(*b);
// 		temp_a = *a;
// 		while (temp_a != NULL && get_content(temp_a) < temp_b)
// 			temp_a = temp_a->next;
// 		qts_maiores = ft_lstsize(temp_a);
// 		printf("qts_maiores = %d\n", qts_maiores);
// 		if (qts_maiores > size_a / 2)
// 			n_rotate = size_a - qts_maiores;
// 		else if (qts_maiores == size_a / 2)
// 			n_rotate = qts_maiores - 1;
// 		else
// 			n_rotate = qts_maiores;
// 		while (n_rotate != 0)
// 		{
// 			if (size_a - qts_maiores <= (size_a) / 2)
// 				rotate_a(a);
// 			else
// 				rev_rot_a(a);
// 			n_rotate--;
// 		}
// 		push_a(a, b);
// 		printf("o size_a vale %f\n", size_a);
// 		if (qts_maiores > size_a / 2)
// 			n_rotate = size_a - qts_maiores;
// 		else if (qts_maiores == size_a / 2)
// 			n_rotate = size_a - qts_maiores - 1;
// 		else
// 			n_rotate = qts_maiores + 1;
// 		signal = 0;
// 		while (n_rotate != 0)
// 		{
// 			if (size_a - qts_maiores <= (size_a) / 2)
// 			{
// 				if (size_a - qts_maiores == (size_a) / 2 && signal == 0)
// 				{	
// 					swap_a(a);
// 					signal = 1;
// 				}
// 				rev_rot_a(a);
// 			}
// 			else
// 				rotate_a(a);
// 			n_rotate--;
// 		}
// 	printf("====================\nstack a: \n");
// 	print_list(*a);
// 	printf("====================\nstack b: \n");
// 	print_list(*b);
// 	}
// }