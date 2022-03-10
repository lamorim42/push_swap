/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:17:48 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/10 18:38:28 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct s_lst {
	int				nbr;
	struct s_lst	*next;
}					t_lst;

typedef struct s_stack {
	char			stk;
	t_lst			*lst;
	unsigned int	len;
}					t_stack;

//list functions
t_lst	*ft_new_elem(int i);
void	ft_push_front(t_lst **head, int i);
//void	ft_push_back(t_lst **last, int i);
void	ft_clean_lst(t_lst **head);
void	ft_delone(t_lst **head);
t_lst	*ft_last_lst(t_lst *head);

//Rules
void	swap(t_lst **head, const char stk);
void	swap_bouth(t_lst **a, t_lst **b);
void	push(t_lst **from, t_lst **to, const char stk);
void	rotate(t_lst **head, const char stk);
void	rotate_bouth(t_lst **a, t_lst **b);
void	rrotate(t_lst **head, const char stk);
void	rrotate_bouth(t_lst **a, t_lst **b);

#endif