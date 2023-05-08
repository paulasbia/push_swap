/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:13 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/08 20:53:28 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_duplicate(t_list *lst, int n)
{
    while (lst)
    {
        if (get_content(lst) != n)
        {
            lst = lst->next;
        }
        else
        {
            return(1);
            break;
        }
    }
    return (0);
}

int	ft_error(char *argv, t_list *temp)
{
	char	*s1;
	char	*s2;
	int		len;

	s1 = argv;
	s2 = ft_itoa(get_content(temp));
	len = ft_strlen(argv);
	if (ft_strncmp(s1, s2, len) != 0)
	{
		return (1);
	}
	return (0);
}
