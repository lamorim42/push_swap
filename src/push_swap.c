/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:18 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/12 13:10:21 by lamorim          ###   ########.fr       */
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

static void	ft_printf_norm(t_lst *lst)
{
	if (!lst)
	{
		ft_printf("Empty list!\n");
		return ;
	}
	while (lst)
	{
		ft_printf("%d\n", lst->norm);
		lst = lst->next;
	}
}

int	ft_can_put_in_lst(char *arg_v)
{
	const char	*nbr;
	int			len;
	int			i;

	nbr = "-0123456789";
	len = ft_strlen(arg_v);
	if (!len)
		return (1);
	i = 0;
	while (i < len)
	{
		if (!ft_strchr(nbr, arg_v[i]))
			return (1);
		i++;
	}
	if (ft_long_atoi(arg_v) > MAX_INT || ft_long_atoi(arg_v) < MIN_INT)
		return (1);
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
	if (ft_gen_stack(&a, argc, argv))
		return (1);
	if (!ft_is_sorted(&(a.lst)))
	{
		ft_clean_lst(&(a.lst));
		return (0);
	}
	ft_printf_lst(a.lst);
	ft_printf("\n---------\n\n");
	ft_normalize(&(a.lst));
	ft_printf_norm(a.lst);
	if (!ft_is_empty(a.lst))
		ft_clean_lst(&(a.lst));
	if (!ft_is_empty(b.lst))
		ft_clean_lst(&(b.lst));
	return (0);
}
