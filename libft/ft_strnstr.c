/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:52:09 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/10/26 05:38:54 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ptrhaystack;
	size_t	l;

	i = 0;
	l = ft_strlen(needle);
	ptrhaystack = (char *)haystack;
	if (needle[0] == '\0')
		return (ptrhaystack);
	while (i < len)
	{
		if (!ft_strncmp(ptrhaystack, needle, l) && l <= len - i)
			return (ptrhaystack);
		ptrhaystack++;
		i++;
	}
	return (NULL);
}
