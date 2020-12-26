/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:02:41 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/11/01 19:28:41 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			j = j + 1;
			i++;
		}
		while (str[i] != c && str[i])
			i++;
	}
	return (j);
}

static char	*loc(char const *str, char c)
{
	char	*locat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
		{
			j = j + 1;
			i++;
		}
	}
	if (!(locat = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	return (locat);
}

static char	*tab_freer(char **split_tab, int i, char *a, char c)
{
	if (!(split_tab[i] = loc(a, c)))
	{
		while (i > 0)
			free(split_tab[--i]);
		free(split_tab);
		split_tab = NULL;
	}
	return (*split_tab);
}

static char	**splitter(char const *str, char *a, char **split_tab, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < words(str, c))
	{
		k = 0;
		if (!(tab_freer(split_tab, i, a, c)))
			return (NULL);
		if (*str)
		{
			while ((str[j] == c) && str[j++])
				a++;
			while ((str[j] != c) && str[j])
			{
				split_tab[i][k++] = str[j++];
				a++;
			}
		}
		split_tab[i++][k] = '\0';
	}
	split_tab[i] = 0;
	return (split_tab);
}

char		**ft_split(char const *str, char c)
{
	char *a;
	char **split_tab;

	if (str == NULL)
		return (NULL);
	a = (char *)str;
	if (!(split_tab = malloc(sizeof(char *) * (words(str, c) + 1))))
		return (NULL);
	return (splitter(str, a, split_tab, c));
}
