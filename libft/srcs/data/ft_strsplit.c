/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:02:52 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:07:23 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	ft_static_nbwords(char const *s, char c)
{
	int		nb;
	int		ktr;
	int		word;

	nb = 0;
	if (s)
	{
		ktr = 0;
		word = 0;
		while (s[ktr] != '\0')
		{
			if (s[ktr] == c)
				word = 0;
			if (word == 0 && s[ktr] != c)
			{
				nb = nb + 1;
				word = 1;
			}
			ktr = ktr + 1;
		}
	}
	return (nb);
}

static int	ft_split(char **tab, char const *s, char c)
{
	int		nb;
	size_t	ktr;
	size_t	ktr2;

	nb = 0;
	ktr = 0;
	while (s[ktr] != '\0')
	{
		ktr2 = 0;
		if (s[ktr] != c)
		{
			while (s[ktr + ktr2] != '\0' && s[ktr + ktr2] != c)
				ktr2 = ktr2 + 1;
			tab[nb] = ft_strsub(s, ktr, ktr2);
			nb = nb + 1;
			ktr = ktr + ktr2;
		}
		else
			ktr = ktr + 1;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb;
	char	**tab;

	if (s)
	{
		nb = ft_static_nbwords(s, c);
		tab = (char **)ft_memalloc(sizeof(*tab) * (nb + 1));
		if (!tab)
			return (NULL);
		nb = ft_split(tab, s, c);
		tab[nb] = '\0';
		return (tab);
	}
	return (NULL);
}
