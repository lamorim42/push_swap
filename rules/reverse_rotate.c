/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:00:42 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/10 18:32:41 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_lst **head, const char stk)
{
	t_lst	*temp;

	if (!*head)
		return ;
	temp = ft_last_lst(*head);
	temp->next = *head;
	*head = temp;
	while (temp->next != *head)
		temp = temp->next;
	temp->next = NULL;
	if (stk != 'n')
		ft_printf("rr%c\n", stk);
}

void	rrotate_bouth(t_lst **a, t_lst **b)
{
	rrotate(a, 'n');
	rrotate(b, 'n');
	ft_printf("rrr\n");
}
