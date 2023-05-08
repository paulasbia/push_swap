/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:31:52 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/08 23:13:41 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		get_content(t_list *elem);
t_list	*my_ft_lstnew(char *content);
int		ft_error(char *argv, t_list *temp);
int		ft_duplicate(t_list *lst, int n);
void    swap_a(t_list **a);
void    swap_b(t_list **b);
void    swap_ss(t_list **a, t_list **b);

#endif