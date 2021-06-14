/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:55:15 by gumartin          #+#    #+#             */
/*   Updated: 2020/02/27 23:47:57 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char		*itoa;
	int			len;
	long int	num;

	len = ft_itoa_len(n);
	num = n;
	if ((itoa = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	itoa[len--] = '\0';
	if (itoa[1] == '\0')
		itoa[0] = '0';
	if (n < 0)
	{
		itoa[0] = '-';
		num *= -1;
	}
	while (num)
	{
		itoa[len] = (num % 10) + '0';
		len--;
		num = num / 10;
	}
	return (itoa);
}
