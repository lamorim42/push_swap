/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:18 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/08 21:24:47 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_printf_lst(t_lst *lst)
{
	while (lst->next)
	{
		ft_printf("%d\n", lst->nbr);
		lst = lst->next;
	}
	ft_printf("%d\n", lst->nbr);
}

static void	ft_init_stack(t_stack *stack)
{
	stack->elem = NULL;
	stack->top = NULL;
	stack->len = 0;
}

int	main(int argc, char **argv)
{
	t_stack a;
	//t_stack b;
	int		i;
	t_lst	*head;

	if (argc <= 2)
		return (1);
	ft_init_stack(&a);
	head = a.elem;
	i = 1;
	while (i < argc)
	{
		if (!head)
			head = ft_new_elem(ft_atoi(argv[i]));
		else
			ft_push_front(&head, ft_atoi(argv[i]));
		i++;
	}
	ft_printf_lst(head);
	swap(&head);
	ft_printf("\n----------\n");
	ft_printf_lst(head);
	ft_clean_lst(&head);
	return (0);
}
