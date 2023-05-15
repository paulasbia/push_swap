/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:41:59 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/15 09:53:18 by pde-souz         ###   ########.fr       */
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
	//t_list	*b;
	t_list	*temp;
	int		i;

	a = NULL;
	//b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		temp = my_ft_lstnew(argv[i]);
		if (ft_error(argv[i], temp) != 0 || ft_duplicate(a, ft_atoi(argv[i])))
		{
			ft_printf("Error\n");
			ft_lstclear(&a, free);
			break ;
		}
		ft_lstadd_back(&a, temp);
		i++;
	}
	sort(&a);
	print_list(a);
	return (0);
}
