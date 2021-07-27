/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:12:36 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/25 11:34:30 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_entry(const char **str, int *signal)
{
	int	pass;

	pass = 0;
	while (*str && (**str == ' ' || **str == '\n' || **str == '\t'
			|| **str == '\v' || **str == '\f' || **str == '\r'))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*signal *= -1;
		(*str)++;
		pass++;
	}
	if (pass > 1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	soma;
	int	signal;

	soma = 0;
	signal = 1;
	if (!(ft_set_entry(&str, &signal)))
		return (0);
	while (*str && *str >= '0' && *str <= '9')
	{
		soma = soma * 10 + (*str - '0');
		++str;
	}
	return (soma * signal);
}
