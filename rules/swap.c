/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:30:02 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/08 21:55:34 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **head)
{
	t_lst	*temp;

	if (!*head)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}