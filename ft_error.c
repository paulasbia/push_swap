/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:13 by pde-souz          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/25 10:04:44 by pde-souz         ###   ########.fr       */
=======
/*   Updated: 2023/05/28 09:55:12 by pde-souz         ###   ########.fr       */
>>>>>>> 126ce38 (feat:valgrind)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate(t_list *lst, int n)
{
	while (lst)
	{
		if (get_content(lst) != n)
			lst = lst->next;
		else
		{
			return (1);
			break ;
		}
	}
	return (0);
}

int	ft_check_error(char *argv, t_list *temp)
{
	char	*s1;
	char	*s2;
	int		len;

	s1 = argv;
	s2 = ft_itoa(get_content(temp));
	len = ft_strlen(argv);
	if (ft_strncmp(s1, s2, len) != 0)
	{
		free(s2);
		return (1);
	}
	free(s2);
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
