/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:53:26 by gumartin          #+#    #+#             */
/*   Updated: 2020/03/04 00:41:35 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (i < len && haystack[i] != '\0')
	{
		k = 0;
		if (haystack[i] == needle[k])
		{
			while ((i + k) < len && needle[k] != '\0' &&
					haystack[i + k] == needle[k])
				k++;
			if (needle[k] == '\0')
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (0);
}
