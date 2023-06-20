/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_utils_ba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:29:43 by pde-souz          #+#    #+#             */
/*   Updated: 2023/06/20 21:26:06 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rev_rot_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_a;
	int	index_b;

	i = 0;
	place_a = ft_find_place_a(a, nbr);
	index_b = ft_find_index(b, nbr);
	if (place_a != 0)
		i = ft_lstsize(a) - place_a;
	if ((i < (ft_lstsize(b) - index_b)) && index_b)
		i = ft_lstsize(b) - index_b;
	return (i);
}

int	ft_rotate_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index_b;

	i = ft_find_place_a(a, nbr);
	index_b = ft_find_index(b, nbr);
	if (i < index_b)
		i = index_b;
	return (i);
}

int	ft_rra_rb_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_a;

	i = 0;
	place_a = ft_find_place_a(a, nbr);
	if (place_a != 0)
		i = ft_lstsize(a) - place_a;
	i = ft_find_index(b, nbr) + i;
	return (i);
}

int	ft_ra_rrb_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index_b;

	i = 0;
	index_b = ft_find_index(b, nbr);
	if (index_b != 0)
		i = ft_lstsize(b) - index_b;
	i = ft_find_place_a(a, nbr) + i;
	return (i);
}
