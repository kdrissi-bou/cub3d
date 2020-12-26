/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 06:13:22 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/10/20 06:13:44 by kdrissi-         ###   ########.fr       */
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
