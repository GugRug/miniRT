/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 00:20:55 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/27 05:24:54 by gumartin         ###   ########.fr       */
/* ************************************************************************** */
/*
** Compares at most the first n bytes of str1 and str2.
** if Return value < 0 then it indicates str1 is less than str2
** if Return value > 0 then it indicates str2 is less than str1.
** if Return value = 0 then it indicates str1 is equal to str2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
