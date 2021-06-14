/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:44:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/02/01 00:22:41 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_src = 0;
	len_dest = 0;
	if (dest == src)
		return (0);
	while (src[len_src] != '\0')
		len_src++;
	while (dest[len_dest] != '\0' && len_dest < size)
		len_dest++;
	i = len_dest;
	while (size && src[i - len_dest] != '\0' && i < (size - 1))
	{
		dest[i] = src[i - len_dest];
		i++;
	}
	if (len_dest < size)
		dest[i] = '\0';
	return (len_dest + len_src);
}
