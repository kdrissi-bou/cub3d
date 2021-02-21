/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:55:14 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 17:55:18 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ptrs;

	ptrs = (char *)s;
	while (*ptrs)
	{
		if (*ptrs == (char)c)
			return (ptrs);
		ptrs++;
	}
	if ((char)c == '\0')
		return (ptrs);
	return (NULL);
}
