/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:33:26 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/23 12:56:34 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate_type_ab(t_list *a, t_list *b)
{
    int     i;
    t_list  *temp;

    temp = a;
    i = ft_case_rrarrb(a, b, get_content(a));
    while (temp != 0)
    {
		if (i > ft_case_rarb(a, b, get_content(temp)))
			i = ft_case_rarb(a, b, get_content(temp));
		if (i > ft_case_rrarrb(a, b, get_content(temp)))
			i = ft_case_rrarrb(a, b, get_content(temp));
		if (i > ft_case_rarrb(a, b, get_content(temp)))
			i = ft_case_rarrb(a, b, get_content(temp));
		if (i > ft_case_rrarb(a, b, get_content(temp)))
			i = ft_case_rrarb(a, b, get_content(temp));
		temp = temp->next;
    }
   printf("i vale %d\n", i);
   return(i);
}