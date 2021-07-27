/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugrug <gustavorugg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########          */
/* ************************************************************************** */
/*
** Cut all ocurrencies of "delim" in "line"
*/

#include "libft.h"

void	ft_strcut(char *line, char *delim)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_strstr(line, delim);
	while (*line != '\0' && line && delim && ptr)
	{
		if (ptr)
		{
			i = ptr - line;
			ft_memmove(&line[i], &line[i + ft_strlen(delim)],
				ft_strlen(line) - i + 1);
			ptr = ft_strstr(line, delim);
			i = 0;
		}
	}
}
