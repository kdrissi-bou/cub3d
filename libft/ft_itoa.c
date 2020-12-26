/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:48:23 by kdrissi-          #+#    #+#             */
/*   Updated: 2019/10/31 01:54:29 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int i;

	i = 0;
	while ((n / 10) != 0)
	{
		i++;
		n = n / 10;
	}
	if (n < 0)
		return (i + 2);
	else
		return (i + 1);
}

static void	print(int j, char *dst, long n, int i)
{
	dst[j--] = '\0';
	while (j >= i)
	{
		dst[j] = (n % 10) + '0';
		n = n / 10;
		j--;
	}
}

char		*ft_itoa(int n)
{
	long	nb;
	char	*dst;
	int		j;

	j = len(n);
	nb = n;
	if (!(dst = malloc(sizeof(char) * j + 1)))
		return (NULL);
	if (n < 0)
	{
		print(j, dst, -nb, 1);
		dst[0] = '-';
	}
	if (n >= 0)
		print(j, dst, nb, 0);
	return (dst);
}
