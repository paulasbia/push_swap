/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:41:59 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/23 09:51:20 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*my_ft_lstnew(char *content)
{
	int	*tmp;

	tmp = malloc(sizeof(int));
	*tmp = ft_atoi(content);
	return (ft_lstnew(tmp));
}

int	get_content(t_list *elem)
{
	return (*((int *)(elem->content)));
}

void	print_list(t_list *a)
{
	t_list	*temp_a;

	temp_a = a;
	while (temp_a != 0)
	{
		ft_printf("%d\n", get_content(temp_a));
		temp_a = temp_a->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*temp;
	int		i;

	a = NULL;
	if (argc < 2)
		ft_error();
	i = 1;
	while (i < argc)
	{
		temp = my_ft_lstnew(argv[i]);
		if (ft_check_error(argv[i], temp) != 0 || ft_duplicate(a, ft_atoi(argv[i])))
		{
			ft_error();
			ft_lstclear(&temp, free);
		}
		ft_lstadd_back(&a, temp);
		i++;
	}
	if (ft_checksorted(a) == 0)
		ft_sort(&a);
	ft_lstclear(&a, free);
//	print_list(a);
	return (0);
}
