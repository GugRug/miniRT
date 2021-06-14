/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:49:19 by gumartin          #+#    #+#             */
/*   Updated: 2020/02/07 20:53:30 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	i = 0;
	s1_c = (unsigned char*)s1;
	s2_c = (unsigned char*)s2;
	while (i++ < n)
		if (s1_c[i - 1] != s2_c[i - 1])
			return (s1_c[i - 1] - s2_c[i - 1]);
	return (0);
}
