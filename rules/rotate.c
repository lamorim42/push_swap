/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:21:12 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/09 20:58:39 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **head, const char stk)
{
	t_lst	*temp;

	if (!*head)
		return ;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	*head = (*head)->next;
	temp = temp->next;
	temp->next = NULL;
	ft_printf("r%c\n", stk);
}
