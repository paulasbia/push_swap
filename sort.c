/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:37:36 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/16 11:26:19 by pde-souz         ###   ########.fr       */
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

void	rule_5(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push_b(b, a);
	rule_3(a);
	sort_a(a, b);
}

void	sort_a(t_list **a, t_list **b)
{	
	int		temp_b;
	t_list	*temp_a;
	double	size_a;
	int		qts_maiores;
	int		n_rotate;

	// printf("stack a: \n");
	// print_list(*a);
	// printf("stack b: \n");
	// print_list(*b);
	while ((*b) != 0)
	{
		size_a = ft_lstsize(*a);
		temp_b = get_content(*b);
		temp_a = *a;
		while (temp_a != NULL && get_content(temp_a) < temp_b)
			temp_a = temp_a->next;
		qts_maiores = ft_lstsize(temp_a);
		//printf("qts_maiores = %d\n", qts_maiores);
		if (qts_maiores > size_a / 2)
			n_rotate = size_a - qts_maiores;
		else
			n_rotate = qts_maiores;
		while (n_rotate != 0)
		{
			if (size_a - qts_maiores <= (size_a) / 2)
				rotate_a(a);
			else
				rev_rot_a(a);
			n_rotate--;
		}
		push_a(a, b);
		if (qts_maiores >= size_a / 2)
			n_rotate = size_a - qts_maiores;
		else
			n_rotate = qts_maiores + 1;
		while (n_rotate != 0)
		{
			if (size_a - qts_maiores <= (size_a) / 2)
				rev_rot_a(a);
			else
				rotate_a(a);
			n_rotate--;
		}
	// printf("====================\nstack a: \n");
	// print_list(*a);
	// printf("====================\nstack b: \n");
	// print_list(*b);
	}
}