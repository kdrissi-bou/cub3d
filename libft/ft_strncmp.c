/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 08:10:55 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/10/26 04:43:06 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*ptrs1;
	char	*ptrs2;

	i = 0;
	ptrs1 = (char *)s1;
	ptrs2 = (char *)s2;
	while (i < n)
	{
		if (ptrs1[i] == ptrs2[i] && ptrs1[i] && ptrs2[i])
			i++;
		else
			return ((unsigned char)ptrs1[i] - (unsigned char)ptrs2[i]);
	}
	return (0);
}
