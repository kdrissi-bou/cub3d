/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:59:28 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/21 17:52:59 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define ULIMIT 1024
# define BUF_SIZE 12
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*gnl_ft_memcpy(char *dst, char *src, size_t n);
char	*join(char *s1, char *s2);
char	*gnl_ft_strchr(char *s, int c);
char	*modified_strdup(char *holder, char c);
int		modified_strlen(char *holder, char c);

#endif
