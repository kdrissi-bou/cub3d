/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 06:47:06 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/10/30 23:31:39 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptrc;

	ptrc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			(ptrc = (char *)s);
		s++;
	}
	if (c == '\0')
		ptrc = (char *)s;
	return (ptrc);
}
