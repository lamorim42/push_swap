/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:06:44 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/02 15:59:30 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_words_count(const char *s, char c);
static char	*ft_get_word(char **s, char c);

char	**ft_split(const char *s, char c)
{
	char	**arr;
	char	*ptr;
	char	*c_ptr;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_words_count(s, c);
	arr = (char **) malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	ptr = ft_strdup(s);
	c_ptr = ptr;
	while (i < words)
	{
		arr[i] = ft_get_word(&ptr, c);
		i++;
	}
	free(c_ptr);
	arr[i] = NULL;
	return (arr);
}

static int	ft_words_count(const char *s, char c)
{
	int	wc;
	int	i;
	int	flag;

	wc = 0;
	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			++wc;
		}
		i++;
	}
	return (wc);
}

static char	*ft_get_word(char **s, char c)
{
	char	*get;
	int		count;

	count = 0;
	while (**s == c)
		(*s)++;
	while ((*s)[count] && (*s)[count] != c)
		count++;
	get = ft_substr(*s, 0, count);
	*s += count;
	return (get);
}
