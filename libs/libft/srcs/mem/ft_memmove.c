/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:57:16 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/25 11:27:46 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst2;
	const unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (i < len && dst != src)
	{
		if (dst > src)
			dst2[len - i - 1] = src2[len - i - 1];
		else
			dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
