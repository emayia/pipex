/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:12:17 by mayyildi          #+#    #+#             */
/*   Updated: 2022/07/09 21:54:05 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[j] = s1[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
