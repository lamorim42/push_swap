/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:30:02 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/09 20:15:23 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **head, const char stk)
{
	t_lst	*temp;

	if (!*head)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	if (stk != 'n')
		ft_printf("s%c\n", stk);
}

void	swap_bouth(t_lst **a, t_lst **b)
{
	swap(a, 'n');
	swap(b, 'n');
	ft_printf("ss\n");
}