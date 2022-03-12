/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:41:00 by lamorim           #+#    #+#             */
/*   Updated: 2022/03/11 19:43:12 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(int c);
static int	ft_signal(int c);

long int	ft_long_atoi(const char *nptr)
{
	int			i;
	int			signal;
	long int	nptr_int;

	i = 0;
	signal = 1;
	nptr_int = 0;
	while (ft_is_space(nptr[i]))
		i++;
	if (ft_signal(nptr[i]))
	{
		if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nptr_int = (nptr_int * 10) + (nptr[i] - '0');
		i++;
	}
	return (nptr_int * signal);
}

static int	ft_is_space(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_signal(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}
