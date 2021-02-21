/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:28:50 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 13:50:44 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		modified_strlen(char *holder, char c)
{
	int i;

	i = 0;
	while (holder[i] != c)
		i++;
	return (i);
}

char	*modified_strdup(char *holder, char c)
{
	char	*ptr1;
	int		i;

	if (holder == NULL)
		return (modified_strdup("", '\0'));
	i = modified_strlen(holder, c);
	ptr1 = malloc(sizeof(char) * (i + 1));
	gnl_ft_memcpy(ptr1, holder, i);
	ptr1[i] = '\0';
	return (ptr1);
}

int		holder_cleaner(char **holder, char **line, char **buf)
{
	char *ptr;

	ptr = *holder;
	*line = modified_strdup(*holder, '\n');
	*holder = modified_strdup(*holder + modified_strlen(*line, '\0') + 1, '\0');
	free(ptr);
	free(*buf);
	*buf = NULL;
	return (1);
}

void	holder_filler(char **holder, char **buf)
{
	char *ptr_holder;

	ptr_holder = *holder;
	*holder = join(*holder, *buf);
	free(ptr_holder);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			i;
	static char	*holder[ULIMIT];

	buf = (char *)malloc(sizeof(char) * (buf_SIZE + 1));
	if (buf_SIZE <= 0 || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (gnl_ft_strchr(holder[fd], '\n'))
		return (holder_cleaner(&holder[fd], line, &buf));
	while ((i = read(fd, buf, buf_SIZE)) > 0)
	{
		buf[i] = '\0';
		holder_filler(&holder[fd], &buf);
		if (gnl_ft_strchr(holder[fd], '\n'))
			return (holder_cleaner(&holder[fd], line, &buf));
	}
	if (i == 0 && !gnl_ft_strchr(holder[fd], '\n'))
	{
		*line = modified_strdup(holder[fd], '\0');
		free(holder[fd]);
		holder[fd] = NULL;
		free(buf);
		return (0);
	}
	return (0);
}
