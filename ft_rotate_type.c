/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:33:26 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/24 16:00:08 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_type_ab(t_list *a, t_list *b)
{
    int     i;
    t_list  *temp;

    temp = a;
    i = ft_case_rrarrb(a, b, get_content(a));
	//printf("em type i eh %d\n", i);
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
 //  printf("i vale %d\n", i);
   return(i);
}

int ft_rotate_type_ba(t_list *a, t_list *b)
{
    int     i;
    t_list  *temp;

    temp = b;
//	printf("o nbr eh %d\n", get_content(b));
    i = ft_case_rrarrb_a(a, b, get_content(b));
    while (temp != 0)
    {
		if (i > ft_case_rarb_a(a, b, get_content(temp)))
			i = ft_case_rarb_a(a, b, get_content(temp));
		if (i > ft_case_rrarrb_a(a, b, get_content(temp)))
			i = ft_case_rrarrb_a(a, b, get_content(temp));
		if (i > ft_case_rarrb_a(a, b, get_content(temp)))
			i = ft_case_rarrb_a(a, b, get_content(temp));
		if (i > ft_case_rrarb_a(a, b, get_content(temp)))
			i = ft_case_rrarb_a(a, b, get_content(temp));
		temp = temp->next;
    }
   return(i);
}