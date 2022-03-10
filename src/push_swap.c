/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:18 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/09 18:22:39by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_printf_lst(t_lst *lst)
{
	if (!lst)
	{
		ft_printf("Empty list!\n");
		return ;
	}
	while (lst->next)
	{
		ft_printf("%d\n", lst->nbr);
		lst = lst->next;
	}
	ft_printf("%d\n", lst->nbr);
}

static int	ft_init_stack(t_stack *stack, char stk)
{
	if (stk != 'a' && stk != 'b')
	{
		ft_dprintf(2, "Error\nBad stack init!\n");
		return (1);
	}
	stack->stk = stk;
	stack->lst = NULL;
	stack->len = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 2)
		return (1);
	ft_init_stack(&a, 'a');
	ft_init_stack(&b, 'b');
	while ((int)a.len + 1 < argc)
	{
		if (!a.lst)
			a.lst = ft_new_elem(ft_atoi(argv[a.len + 1]));
		else
			ft_push_front(&(a.lst), ft_atoi(argv[a.len + 1]));
		a.len++;
	}
	push(&(a.lst), &(b.lst), b.stk);
	push(&(b.lst), &(a.lst), a.stk);
	ft_printf_lst(a.lst);
	ft_clean_lst(&(a.lst));
	return (0);
}
