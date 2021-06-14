/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:07:11 by gumartin          #+#    #+#             */
/*   Updated: 2020/02/07 22:22:23 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int	i;

	i = 0;
	while ((int)n-- > 0 && (dst != src))
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
