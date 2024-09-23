/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:56:48 by mayyildi          #+#    #+#             */
/*   Updated: 2022/07/09 21:54:23 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *) str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] != '\0' && i + j < len
				&& str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return ((char *) str + i);
		}
		i++;
	}
	return (0);
}
