/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 02:43:30 by gumartin          #+#    #+#             */
/*   Updated: 2020/02/27 23:40:50 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	int				putnbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = n * (-1);
	}
	else
		num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	putnbr = (num % 10) + '0';
	write(fd, &putnbr, 1);
}
