/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:18 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/13 18:31:41 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	ft_init_stack(&a, 'a');
	ft_init_stack(&b, 'b');
	if (ft_gen_stack(&a, argc, argv))
		return (1);
	if (!ft_is_sorted(&(a.lst)))
	{
		ft_clean_lst(&(a.lst));
		return (0);
	}
	push_swap(&a, &b, argc);
	return (0);
}

void	push_swap(t_stack *a, t_stack *b, int arg_c)
{
	ft_normalize(&(a->lst));
	if (arg_c == 3 || arg_c == 4)
		sort_three(&(a->lst));
	else if (arg_c == 5 || arg_c == 6)
		sort_five(&(a->lst), &(b->lst), FALSE);
	else if (arg_c == 7)
		sort_six(&(a->lst), &(b->lst));
	else if (arg_c > 7)
		radix_sort(&(a->lst), &(b->lst), (int)a->len);
	if (!ft_is_empty(a->lst))
		ft_clean_lst(&(a->lst));
	if (!ft_is_empty(b->lst))
		ft_clean_lst(&(b->lst));
}

void	radix_sort(t_lst **a, t_lst **b, int len)
{
	int		i;
	int		j;

	i = 0;
	while (ft_is_sorted(a))
	{
		j = 0;
		while (j < len)
		{
			if (((*a)->norm >> i) & 1)
				rotate(a, 'a');
			else
				push(a, b, 'b');
			j++;
		}
		while (!ft_is_empty(*b))
			push(b, a, 'a');
		i++;
	}
}
