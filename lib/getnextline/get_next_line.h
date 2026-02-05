/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:00:50 by apestana          #+#    #+#             */
/*   Updated: 2025/03/17 03:19:33 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*get_next_line_utils*/
size_t	ft_get_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_get_strjoin(char *s1, char *s2);

size_t	ft_get_strlen(const char *s);

char	*ft_get_strchr(const char *s, int c);

char	*ft_get_substr(char const *s, unsigned int start, size_t len);

/*get_next_line*/
char	*get_next_line(int fd, int end);

char	*ft_get_memory_liberator(char **str);

#endif