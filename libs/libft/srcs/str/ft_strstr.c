/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugrug <gustavorugg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########          */
/* ************************************************************************** */
/*
** Return a pointer to the first "needle" inside "haystack"
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		k = 0;
		if (haystack[i] == needle[k])
		{
			while (haystack[i + k] != '\0' && needle[k] != '\0'
				&& haystack[i + k] == needle[k])
				k++;
			if (needle[k] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
