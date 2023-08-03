/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:26:37 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/03 10:27:06 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_place_b(t_list *b, int nbr)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (nbr > get_content(b) && nbr < get_content(ft_lstlast(b)))
		i = 0;
	else if (nbr > ft_find_bigger(b) || nbr < ft_find_smaller(b))
		i = ft_find_index(b, ft_find_bigger(b));
	else
	{
		temp = b->next;
		while (get_content(b) < nbr || get_content(temp) > nbr)
		{
			b = b->next;
			temp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_bigger(t_list *lst)
{
	int	i;

	i = get_content(lst);
	while (lst != 0)
	{
		if (get_content(lst) > i)
			i = get_content(lst);
		lst = lst->next;
	}
	return (i);
}

int	ft_find_smaller(t_list *lst)
{
	int	i;

	i = get_content(lst);
	while (lst != 0)
	{
		if (get_content(lst) < i)
			i = get_content(lst);
		lst = lst->next;
	}
	return (i);
}

int	ft_find_index(t_list *lst, int nbr)
{
	int	i;

	i = 0;
	while (get_content(lst) != nbr)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_find_place_a(t_list *a, int nbr)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (nbr < get_content(a) && nbr > get_content(ft_lstlast(a)))
		i = 0;
	else if (nbr > ft_find_bigger(a) || nbr < ft_find_smaller(a))
		i = ft_find_index(a, ft_find_smaller(a));
	else
	{
		temp = a->next;
		while (get_content(a) > nbr || get_content(temp) < nbr)
		{
			a = a->next;
			temp = a->next;
			i++;
		}
	}
	return (i);
}
