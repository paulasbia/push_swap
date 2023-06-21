/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:31:52 by pde-souz          #+#    #+#             */
/*   Updated: 2023/06/21 09:58:04 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


/* --- Dependencies Libs --- */

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


/* --Auxiliar create list --- */

int		get_content(t_list *elem);
t_list	*my_ft_lstnew(char *content);
int		ft_check_error(char *argv, t_list *temp);
void	ft_error(void);
int		ft_duplicate(t_list *lst, int n);
int		ft_sorted(t_list *stack_a);

/* --- Moves --- */

void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ss(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **b, t_list **a);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_rr(t_list **a, t_list **b);
void	rev_rot_b(t_list **b);
void	rev_rot_a(t_list **a);
void	rev_rot_ab(t_list **a, t_list **b);
t_list	*ft_remove_back(t_list **list);
t_list	*ft_remove_front(t_list **list);

/* --- Functions to sort list_b--- */

void	print_list(t_list *a);
void	ft_sort_list(t_list **a);
t_list	*ft_sort_b(t_list **lst_a);
void	ft_sort_b_3(t_list **lst_a, t_list **lst_b);
int		ft_choose_rotate_ab(t_list *a, t_list *b);
int		ft_find_place_b(t_list *a, int nbr);
int		ft_find_bigger(t_list *lst);
int		ft_find_smaller(t_list *lst);
int		ft_find_index(t_list *lst, int nbr);

/* --- Functions case and do list_b--- */

int		ft_rev_rot(t_list *a, t_list *b, int nbr);
int		ft_rra_rb(t_list *a, t_list *b, int nbr);
int		ft_ra_rrb(t_list *a, t_list *b, int nbr);
int		ft_rotate(t_list *a, t_list *b, int nbr);

int		ft_do_rotate(t_list **a, t_list **b, int nbr, char s);
int		ft_do_rev_rot(t_list **a, t_list **b, int nbr, char s);
int		ft_do_rra_rb(t_list **a, t_list **b, int nbr, char s);
int		ft_do_ra_rrb(t_list **a, t_list **b, int nbr, char s);

/* --- Functions case and do list_a--- */

t_list	**ft_sort_a(t_list **lst_a, t_list **lst_b);
int		ft_choose_rotate_ba(t_list *a, t_list *b);

int		ft_ra_rrb_a(t_list *a, t_list *b, int nbr);
int		ft_rra_rb_a(t_list *a, t_list *b, int nbr);
int		ft_rotate_a(t_list *a, t_list *b, int nbr);
int		ft_rev_rot_a(t_list *a, t_list *b, int nbr);

int		ft_find_place_a(t_list *a, int nbr);

void	rule_3(t_list **a);

#endif