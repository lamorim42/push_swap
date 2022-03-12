/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:44:45 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/12 12:51:07 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_lst **head)
{
	t_lst	*slow;
	t_lst	*fast;
	int		temp;

	slow = *head;
	fast = (*head)->next;
	while (ft_is_sorted(head))
	{
		if (slow->nbr > fast->nbr)
		{
			temp = slow->nbr;
			slow->nbr = fast->nbr;
			fast->nbr = temp;
		}
		slow = slow->next;
		fast = fast->next;
		if (!fast)
		{
			slow = *head;
			fast = (*head)->next;
		}
	}
}
