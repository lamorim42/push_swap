/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:13:31 by lamorim           #+#    #+#             */
/*   Updated: 2021/08/17 18:52:51 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(long int c);
static char	*ft_return_str(char *str, int i, long int n, int signal);

char	*ft_itoa(int n)
{
	char		*str_n;
	int			signal;
	long int	cpy_n;
	int			count;
	int			i;

	signal = 0;
	cpy_n = n;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
	{
		cpy_n *= -1;
		signal = 1;
	}
	count = ft_count_digit(cpy_n);
	str_n = (char *) malloc(count + signal + 1);
	if (str_n == NULL)
		return (NULL);
	i = count + signal;
	str_n[i] = '\0';
	i -= 1;
	return (ft_return_str(str_n, i, cpy_n, signal));
}

static int	ft_count_digit(long int c)
{
	int	count;

	count = 0;
	while (c > 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

static char	*ft_return_str(char *str, int i, long int n, int signal)
{
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		if (i == 0 && signal == 1)
			str[i] = '-';
		i--;
		n /= 10;
	}
	return (str);
}
