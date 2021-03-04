/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:51:24 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/10/17 17:51:31 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	i = 0;
	ptrsrc = (unsigned char*)src;
	ptrdst = (unsigned char*)dst;
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		if (ptrsrc[i] == (unsigned char)c)
			return (ptrdst + i + 1);
		i++;
	}
	return (NULL);
}
