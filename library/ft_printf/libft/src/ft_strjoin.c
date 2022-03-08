/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:49:36 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/24 12:22:18 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	join = (char *) malloc(s1_len + s2_len + 1);
	if (!join)
		return (NULL);
	i = -1;
	while (++i < (int)s1_len + 1)
		join[i] = s1[i];
	i = -1;
	while (++i < (int)s2_len + 1)
		join[s1_len + i] = s2[i];
	return (join);
}
