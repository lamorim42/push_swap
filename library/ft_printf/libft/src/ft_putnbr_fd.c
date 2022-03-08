/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:37:48 by lamorim           #+#    #+#             */
/*   Updated: 2021/08/18 18:03:12 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_long;
	char		digit;

	n_long = n;
	if (n_long < 0)
	{
		n_long = -n_long;
		write(fd, "-", 1);
	}
	if (n_long > 9)
		ft_putnbr_fd(n_long / 10, fd);
	digit = '0' + (n_long % 10);
	write(fd, &digit, 1);
}
