/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:58:22 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/03 10:26:34 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_do_rotate(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (get_content(*a) != nbr && ft_find_place_b(*b, nbr) > 0)
			rotate_rr(a, b);
		while (get_content(*a) != nbr)
			rotate_a(a);
		while (ft_find_place_b(*b, nbr) > 0)
			rotate_b(b);
		push_b(b, a);
	}
	else
	{
		while (get_content(*b) != nbr && ft_find_place_a(*a, nbr) > 0)
			rotate_rr(a, b);
		while (get_content(*b) != nbr)
			rotate_b(b);
		while (ft_find_place_a(*a, nbr) > 0)
			rotate_a(a);
		push_a(a, b);
	}
	return (-1);
}

int	ft_do_rev_rot(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (get_content(*a) != nbr && ft_find_place_b(*b, nbr) > 0)
			rev_rot_ab(a, b);
		while (get_content(*a) != nbr)
			rev_rot_a(a);
		while (ft_find_place_b(*b, nbr) > 0)
			rev_rot_b(b);
		push_b(b, a);
	}
	else
	{
		while (get_content(*b) != nbr && ft_find_place_a(*a, nbr) > 0)
			rev_rot_ab(a, b);
		while (get_content(*b) != nbr)
			rev_rot_b(b);
		while (ft_find_place_a(*a, nbr) > 0)
			rev_rot_a(a);
		push_a(a, b);
	}
	return (-1);
}

int	ft_do_rra_rb(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (get_content(*a) != nbr)
			rev_rot_a(a);
		while (ft_find_place_b(*b, nbr) > 0)
			rotate_b(b);
		push_b(b, a);
	}
	else
	{
		while (ft_find_place_a(*a, nbr) > 0)
			rev_rot_a(a);
		while (get_content(*b) != nbr)
			rotate_b(b);
		push_a(a, b);
	}
	return (-1);
}

int	ft_do_ra_rrb(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (get_content(*a) != nbr)
			rotate_a(a);
		while (ft_find_place_b(*b, nbr) > 0)
			rev_rot_b(b);
		push_b(b, a);
	}
	else
	{
		while (ft_find_place_a(*a, nbr) > 0)
			rotate_a(a);
		while (get_content(*b) != nbr)
			rev_rot_b(b);
		push_a(a, b);
	}
	return (-1);
}
