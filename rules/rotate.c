/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:21:12 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/11 19:16:14 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **head, const char stk)
{
	t_lst	*temp;

	if (!*head)
		return ;
	temp = ft_last_lst(*head);
	temp->next = *head;
	*head = (*head)->next;
	temp = temp->next;
	temp->next = NULL;
	if (stk != 'n')
		ft_printf("r%c\n", stk);
}

void	rotate_bouth(t_lst **a, t_lst **b)
{
	rotate(a, 'n');
	rotate(b, 'n');
	ft_printf("rr\n");
}
