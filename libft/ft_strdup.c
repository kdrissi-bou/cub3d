/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:58:04 by kdrissi-          #+#    #+#             */
/*   Updated: 2020/12/21 23:29:27 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptrs1;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	i = 0;
	if (!(ptrs1 = malloc((sizeof(char)) * len)))
		return (NULL);
	ft_memcpy(ptrs1, s1, len);
	return (ptrs1);
}
