/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:57:48 by gumartin          #+#    #+#             */
/*   Updated: 2020/03/04 03:13:50 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	ft_cont_words(const char *s, char c)
{
	int	i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static int	strlen_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*create_word(char const *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = strlen_sep(s, c);
	i = 0;
	word = (char*)malloc(sizeof(char) * len + 1);
	if (word == NULL)
		return (NULL);
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_put_split(char **split, const char *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			word = create_word(&(s[i]), c);
			split[j] = word;
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	split[j] = NULL;
	return (split);
}

char		**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * (ft_cont_words(s, c) + 1))))
		return (NULL);
	return (ft_put_split(split, s, c));
}
