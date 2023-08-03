/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:40:41 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/03 10:26:58 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sorted(t_list *stack_a)
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
