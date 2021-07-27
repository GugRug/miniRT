/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:47:37 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/25 11:08:12 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (s != NULL)
	{
		sub = (char *)malloc(sizeof (char) * (len + 1));
		if (!sub)
			return (0);
		i = 0;
		while (i < len && (i + start < ft_strlen(s)))
		{
			sub[i] = s[i + start];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
