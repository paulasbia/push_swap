/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:40:41 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/24 15:58:57 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function checks if the stack is sorted.
int	ft_checksorted(t_list *stack_a)
{
	int	i;

	i = get_content(stack_a);
	while (stack_a != 0)
	{
		if (i > get_content(stack_a))
			return (0);
		i = get_content(stack_a);
		stack_a = stack_a->next;
	}
	return (1);
}
