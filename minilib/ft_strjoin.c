/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:10:05 by mayyildi          #+#    #+#             */
/*   Updated: 2022/07/09 21:54:09 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		tlen;
	char	*joined;

	i = 0;
	j = 0;
	tlen = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(tlen + 1);
	if (!joined)
		return (NULL);
	i = ft_strcpy(joined, s1);
	while (s2[j])
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[i] = 0;
	return (joined);
}
