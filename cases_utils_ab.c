/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_utils_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:22:03 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/25 10:04:27 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rrarrb(t_list *a, t_list *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, nbr) != 0)
		i = ft_lstsize(b) - ft_find_place_b(b, nbr);
	if ((i < (ft_lstsize(a) - ft_find_index(a, nbr))) && ft_find_index(a, nbr))
		i = ft_lstsize(a) - ft_find_index(a, nbr);
	return (i);
}

int	ft_case_rarb(t_list *a, t_list *b, int nbr)
{
	int	i;

	i = ft_find_place_b(b, nbr);
	if (i < ft_find_index(a, nbr))
		i = ft_find_index(a, nbr);
	return (i);
}

int	ft_case_rarrb(t_list *a, t_list *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, nbr) != 0)
		i = ft_lstsize(b) - ft_find_place_b(b, nbr);
	i = ft_find_index(a, nbr) + i;
	return (i);
}

int	ft_case_rrarb(t_list *a, t_list *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(a, nbr) != 0)
		i = ft_lstsize(a) - ft_find_index(a, nbr);
	i = ft_find_place_b(b, nbr) + i;
	return (i);
}
