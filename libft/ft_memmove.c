/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:19:50 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/10/26 02:51:21 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;
	size_t			i;
	size_t			j;

	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	i = 0;
	j = len - 1;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (i < len)
	{
		if (ptrdst > ptrsrc)
		{
			ptrdst[j] = ptrsrc[j];
			j--;
		}
		else
			ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (dst);
}
