/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:01:54 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/13 15:00:14 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chose_rules(t_lst **first, t_lst	**second, t_lst	**third, \
t_lst **head)
{
	if ((*first)->norm < (*second)->norm && (*second)->norm > (*third)->norm)
	{
		if ((*first)->norm < (*third)->norm)
		{
			swap(head, 'a');
			rotate(head, 'a');
		}
		else
			rrotate(head, 'a');
	}
	else if ((*first)->norm > (*second)->norm \
	&& (*second)->norm < (*third)->norm)
	{
		if ((*first)->norm < (*third)->norm)
			swap(head, 'a');
		else
			rotate(head, 'a');
	}
	else if ((*first)->norm > (*second)->norm \
	&& (*second)->norm > (*third)->norm)
	{
		rotate(head, 'a');
		swap(head, 'a');
	}
}

void	sort_three(t_lst **head)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*third;

	first = *head;
	second = first->next;
	third = second->next;
	if (!third && (first->norm > second->norm))
		swap(head, 'a');
	if (!first || !second || !third)
		return ;
	ft_chose_rules(&first, &second, &third, head);
}

void	ft_min_totop(t_lst **head, int min, char stk)
{
	t_lst	*temp;

	temp = *head;
	while (min != temp->norm)
	{
		temp = temp->next;
		rotate(head, stk);
	}
}

void	sort_five(t_lst **head_a, t_lst **head_b, int min_ok)
{
	int		min;

	min = 0 + min_ok;
	ft_min_totop(head_a, min, 'a');
	if (!ft_is_sorted(head_a))
	{
		if (min_ok)
			push(head_b, head_a, 'a');
		return ;
	}
	push(head_a, head_b, 'b');
	min = 1 + min_ok;
	ft_min_totop(head_a, min, 'a');
	if (!ft_is_sorted(head_a))
	{
		if (min_ok)
			push(head_b, head_a, 'a');
		push(head_b, head_a, 'a');
		return ;
	}
	push(head_a, head_b, 'b');
	sort_three(head_a);
	push(head_b, head_a, 'a');
	push(head_b, head_a, 'a');
}

void	sort_six(t_lst **head_a, t_lst **head_b)
{
	int		min;
	t_lst	*temp;

	min = 0;
	temp = *head_a;
	ft_min_totop(head_a, min, 'a');
	push(head_a, head_b, 'b');
	sort_five(head_a, head_b, TRUE);
	if (!ft_is_empty(*head_b))
		push(head_b, head_a, 'a');
}
