/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:31:52 by pde-souz          #+#    #+#             */
/*   Updated: 2023/05/23 13:21:32 by pde-souz         ###   ########.fr       */
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
int		ft_check_error(char *argv, t_list *temp);
void	ft_error(void);
int		ft_duplicate(t_list *lst, int n);
int	ft_checksorted(t_list *stack_a);
void    swap_a(t_list **a);
void    swap_b(t_list **b);
void    swap_ss(t_list **a, t_list **b);
void    push_a(t_list **a, t_list **b);
void    push_b(t_list **b, t_list **a);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_rr(t_list **a, t_list **b);
void	rev_rot_b(t_list **b);
void	rev_rot_a(t_list **a);
void	rev_rot_ab(t_list **a, t_list **b);
t_list  *ft_remove_back(t_list **list);
t_list  *ft_remove_front(t_list **list);
void	print_list(t_list *a);
void    ft_sort(t_list **a);
t_list	*ft_sort_b(t_list **stack_a);
void	ft_sort_b_till_3(t_list **stack_a, t_list **stack_b);
int ft_rotate_type_ab(t_list *a, t_list *b);
int ft_find_place_b(t_list *a, int nbr);
int ft_find_max(t_list *lst);
int ft_find_min(t_list *lst);
int ft_find_index(t_list *lst, int nbr);

int ft_case_rrarrb(t_list *a, t_list *b, int nbr);
int	ft_case_rrarb(t_list *a, t_list *b, int nbr);
int	ft_case_rarrb(t_list *a, t_list *b, int nbr);
int	ft_case_rarb(t_list *a, t_list *b, int nbr);

int ft_apply_rarb(t_list **a, t_list **b, int nbr, char s);
int	ft_apply_rrarrb(t_list **a, t_list **b, int nbr, char s);
int	ft_apply_rrarb(t_list **a, t_list **b, int nbr, char s);
int	ft_apply_rarrb(t_list **a, t_list**b, int nbr, char s);

void    rule_3(t_list **a);
void    rule_5(t_list **a, t_list **b);
void	sort_a(t_list **a, t_list **b);

#endif