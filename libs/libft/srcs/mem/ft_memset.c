/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 03:01:14 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/25 11:27:46 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*b2;

	b2 = b;
	while (len-- > 0)
	{
		*(unsigned char *)b2 = (unsigned char)c;
		b2++;
	}
	return (b);
}
