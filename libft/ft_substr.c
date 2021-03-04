/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 00:25:17 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/11/01 17:38:23 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptrdst;
	size_t	i;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len >= (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start > len_s)
		return (ft_strdup(""));
	if (!(ptrdst = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		ptrdst[i] = s[i + start];
		i++;
	}
	ptrdst[i] = '\0';
	return (ptrdst);
}
