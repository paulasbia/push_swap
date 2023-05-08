/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:41:59 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/08 16:33:56 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    // t_list  *a;
    // t_list  *b;
    int     i;
    
    if (argc < 2)
        return (0);
    i = 0;
    while (i < argc)
    {
        ft_printf("%s\n", argv[i]);
        i++;
    }
    return (0);
}