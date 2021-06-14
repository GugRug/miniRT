/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:58:37 by gumartin          #+#    #+#             */
/*   Updated: 2021/06/13 23:24:56 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	i = -1;
	while (++i < nmemb * size)
		p[i] = '\0';
	return (p);
}
