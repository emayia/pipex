/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:27:58 by mayyildi          #+#    #+#             */
/*   Updated: 2022/07/09 21:53:52 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_diviser(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			i++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (i);
}

static char	*ft_copy(char const *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] && (s[i] != c))
		i++;
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	while (s[j] && (j < i))
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cut;
	char	**tab;

	i = 0;
	cut = ft_diviser(s, c);
	tab = malloc(sizeof(*tab) * (cut + 1));
	if ((!s) || (!tab))
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			tab[i++] = ft_copy(s, c);
			while (*s && (*s != c))
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
