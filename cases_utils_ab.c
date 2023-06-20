/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_utils_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:22:03 by pde-souz          #+#    #+#             */
/*   Updated: 2023/06/20 18:44:06 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rev_rot(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_b;
	int	index_a;

	place_b = ft_find_place_b(b, nbr);
	index_a = ft_find_index(a, nbr);
	i = 0;
	if (place_b != 0)
		i = ft_lstsize(b) - place_b;
	if ((i < (ft_lstsize(a) - index_a)) && index_a)
		i = ft_lstsize(a) - index_a;
	return (i);
}

int	ft_rotate(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index;

	i = ft_find_place_b(b, nbr);
	index = ft_find_index(a, nbr);
	if (i < index)
		i = index;
	return (i);
}

int	ft_rarrb(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_b;

	i = 0;
	place_b = ft_find_place_b(b, nbr);
	if (place_b != 0)
		i = ft_lstsize(b) - place_b;
	i = ft_find_index(a, nbr) + i;
	return (i);
}

int	ft_rrarb(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index;

	i = 0;
	index = ft_find_index(a, nbr);
	if (index != 0)
		i = ft_lstsize(a) - index;
	i = ft_find_place_b(b, nbr) + i;
	return (i);
}
