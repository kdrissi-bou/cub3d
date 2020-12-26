/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 08:38:09 by kdrissi-          #+#    #+#             */
/*   Updated: 2020/12/21 23:29:38 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	if (len + 1 > size)
	{
		dst = ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	else
		dst = ft_memcpy(dst, src, len + 1);
	return (len);
}
