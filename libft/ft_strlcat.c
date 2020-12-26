/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 08:31:23 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/11/01 19:23:03 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	j;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	j = ft_strlen(src);
	i = ft_strlen(dst);
	k = 0;
	if (size == 0)
		return (j);
	if (size <= i)
		return (j + size);
	else
		j = j + i;
	while (src[k] != '\0' && i < (size - 1))
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (j);
}
