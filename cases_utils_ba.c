/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_utils_ba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:29:43 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/23 15:14:49 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_case_rrarrb_a(t_list *a, t_list *b, int nbr)
{
    int i;

    i = 0;
    if (ft_find_place_a(a, nbr) != 0)
		i = ft_lstsize(a) - ft_find_place_a(a, nbr);
	if ((i < (ft_lstsize(b) - ft_find_index(b, nbr))) && ft_find_index(b, nbr))
		i = ft_lstsize(b) - ft_find_index(b, nbr);
	printf("rrarrb i vale %d\n", i);
	return (i);
}

int	ft_case_rarb_a(t_list *a, t_list *b, int nbr)
{
	int	i;

	i = ft_find_place_a(a, nbr);
	if (i < ft_find_index(b, nbr))
		i = ft_find_index(b, nbr);
	return (i);	
}

int	ft_case_rrarb_a(t_list *a, t_list *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, nbr) != 0)
		i = ft_lstsize(a) - ft_find_place_a(a, nbr);
	i = ft_find_index(b, nbr) + i;
	return(i);
}

int	ft_case_rarrb_a(t_list *a, t_list *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(b, nbr) != 0)
		i = ft_lstsize(b) - ft_find_index(b, nbr);
	i = ft_find_place_a(a, nbr) + i;
}
