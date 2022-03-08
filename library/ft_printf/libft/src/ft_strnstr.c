/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:14:20 by lamorim           #+#    #+#             */
/*   Updated: 2021/08/13 13:38:53 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_i;
	size_t	lit_i;
	size_t	len_lit;
	char	*big_cpy;

	big_i = 0;
	lit_i = 0;
	len_lit = ft_strlen(little);
	big_cpy = (char *) big;
	if (len_lit == 0)
		return (big_cpy);
	while (big_cpy[big_i] != '\0' && len-- >= len_lit)
	{
		if (big_cpy[big_i] == little[lit_i]
			&& !ft_strncmp(big_cpy + big_i, little, len_lit))
			return (big_cpy + big_i);
		big_i++;
	}
	return (NULL);
}
