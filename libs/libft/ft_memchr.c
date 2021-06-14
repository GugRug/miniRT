/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:30:24 by gumartin          #+#    #+#             */
/*   Updated: 2020/02/07 20:36:02 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char*)s;
	while (i++ < n)
		if (s2[i - 1] == (unsigned char)c)
			return (&(s2[i - 1]));
	return (NULL);
}
