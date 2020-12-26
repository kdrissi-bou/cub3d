/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:21:17 by kdrissi-          #+#    #+#             */
/*   Updated: 2020/12/21 23:30:43 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *set, char const *s1, size_t i)
{
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			return (i);
	}
	return (0);
}

static	size_t	count1(char const *set, char const *s1, size_t i)
{
	while (i != 0)
	{
		if (ft_strchr(set, s1[i]))
			i--;
		else
			return (i + 1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	len_s1;
	size_t	start;
	size_t	len_trimed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (len_s1 == 0)
		return (ft_strdup(""));
	start = count(set, s1, 0);
	len_trimed = len_s1 - start - (len_s1 - count1(set, s1, len_s1 - 1));
	trimed = ft_substr(s1, start, len_trimed);
	return (trimed);
}
