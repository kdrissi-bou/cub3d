/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:59:06 by kdrissi-          #+#    #+#             */
/*   Updated: 2020/12/21 23:25:38 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_memcpy(char *dst, char *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptrsrc = (unsigned char *)src;
	ptrdst = (unsigned char *)dst;
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (dst);
}

char	*join(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (dst = modified_strdup(s2, '\0'));
	if (!(dst = malloc(modified_strlen(s1, '\0')
		+ modified_strlen(s2, '\0') + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

char	*gnl_ft_strchr(char *s, int c)
{
	char *ptrs;

	ptrs = (char *)s;
	if (s == NULL)
		return (NULL);
	while (*ptrs != '\0')
	{
		if (*ptrs == (char)c)
			return (ptrs);
		ptrs++;
	}
	if ((char)c == '\0')
		return (ptrs);
	return (NULL);
}
