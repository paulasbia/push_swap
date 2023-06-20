/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:37:36 by pde-souz          #+#    #+#             */
/*   Updated: 2023/06/20 21:24:40 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list(t_list **lst_a)
{
	t_list	*lst_b;
	int		i;

	lst_b = NULL;
	if (ft_lstsize(*lst_a) == 2)
		swap_a(lst_a);
	if (ft_lstsize(*lst_a) == 3)
		rule_3(lst_a);
	else
	{
		lst_b = ft_sort_b(lst_a);
		lst_a = ft_sort_a(lst_a, &lst_b);
		i = ft_find_index(*lst_a, ft_find_min(*lst_a));
		if (i < ft_lstsize(*lst_a) - i)
		{
			while (get_content(*lst_a) != ft_find_min(*lst_a))
				rotate_a(lst_a);
		}
		else
		{
			while (get_content(*lst_a) != ft_find_min(*lst_a))
				rev_rot_a(lst_a);
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

t_list	*ft_sort_b(t_list **lst_a)
{
	t_list	*lst_b;
	int		sorted_a;

	lst_b = NULL;
	sorted_a = ft_sorted(*lst_a);
	if (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
		push_b(&lst_b, lst_a);
	if (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
		push_b(&lst_b, lst_a);
	if (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
		ft_sort_b_3(lst_a, &lst_b);
	if (sorted_a == 0)
		rule_3(lst_a);
	return (lst_b);
}

void	ft_sort_b_3(t_list **lst_a, t_list **lst_b)
{
	int		i;
	int		sorted_a;
	t_list	*temp;

	sorted_a = ft_sorted(*lst_a);
	while (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
	{
		temp = *lst_a;
		i = ft_rotate_type_ab(*lst_a, *lst_b);
		while (i >= 0)
		{
			if (i == ft_rotate(*lst_a, *lst_b, get_content(temp)))
				i = ft_do_rotate(lst_a, lst_b, get_content(temp), 'a');
			else if (i == ft_rev_rot(*lst_a, *lst_b, get_content(temp)))
				i = ft_do_rev_rot(lst_a, lst_b, get_content(temp), 'a');
			else if (i == ft_ra_rrb(*lst_a, *lst_b, get_content(temp)))
				i = ft_do_ra_rrb(lst_a, lst_b, get_content(temp), 'a');
			else if (i == ft_rra_rb(*lst_a, *lst_b, get_content(temp)))
				i = ft_do_rra_rb(lst_a, lst_b, get_content(temp), 'a');
			else
				temp = temp->next;
		}
	}
}

t_list	**ft_sort_a(t_list **lst_a, t_list **lst_b)
{
	int		i;
	t_list	*temp;

	while (*lst_b != 0)
	{
		temp = *lst_b;
		i = ft_rotate_type_ba(*lst_a, *lst_b);
		while (i >= 0)
		{
			if (i == ft_rotate_a(*lst_a, *lst_b, get_content(temp)))
				i = ft_do_rotate(lst_a, lst_b, get_content(temp), 'b');
			else if (i == ft_ra_rrb_a(*lst_a, *lst_b,
					get_content(temp)))
				i = ft_do_ra_rrb(lst_a, lst_b, get_content(temp), 'b');
			else if (i == ft_rev_rot_a(*lst_a, *lst_b,
					get_content(temp)))
				i = ft_do_rev_rot(lst_a, lst_b, get_content(temp), 'b');
			else if (i == ft_rra_rb_a(*lst_a, *lst_b,
					get_content(temp)))
				i = ft_do_rra_rb(lst_a, lst_b, get_content(temp), 'b');
			else
				temp = temp->next;
		}
	}
	return (lst_a);
}
