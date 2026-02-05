/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:01:43 by apestana          #+#    #+#             */
/*   Updated: 2025/03/17 16:56:29 by apestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
1-last buffer is the static variable
2-fd is the file descriptor
This functions only reads if the static buffer doesn't has an endl.
In the loop, the functions adds BUFFER_SIZE chars to the static buffer
*/
static char	*ft_read(int fd, char *last_buffer)
{
	char	*new_buffer;
	ssize_t	bytes_read;

	new_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (new_buffer == NULL)
		return (ft_get_memory_liberator(&last_buffer));
	bytes_read = 1;
	new_buffer[0] = '\0';
	while (bytes_read > 0
		&& ft_get_strchr((const char *)new_buffer, '\n') == NULL)
	{
		bytes_read = read(fd, new_buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			new_buffer[bytes_read] = '\0';
			last_buffer = ft_get_strjoin(last_buffer, new_buffer);
		}
	}
	free(new_buffer);
	if (bytes_read == -1)
	{
		return (ft_get_memory_liberator(&last_buffer));
	}
	return (last_buffer);
}

char	*ft_get_memory_liberator(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static char	*ft_refresh(char *last_buffer, char *aux)
{
	char	*new_buffer;
	int		i;

	if (aux == NULL)
	{
		new_buffer = NULL;
		return (ft_get_memory_liberator(&last_buffer));
	}
	i = aux - last_buffer + 1;
	if (last_buffer[i] == '\0')
		return (ft_get_memory_liberator(&last_buffer));
	new_buffer = ft_get_substr((const char *)last_buffer, i,
			ft_get_strlen((const char *)last_buffer) - i);
	ft_get_memory_liberator(&last_buffer);
	return (new_buffer);
}

/*
This function returns a text next line.
It has 5 sections:
0) Protections againts fd, bad buffer_size and read errors.
1) Read the file (only if necesary) for endl.
2) Look for the endl on the buffer.
3) Put a portion of the buffer ended on endl on a sub-string 
4) Clean the buffer
*/
char	*get_next_line(int fd, int end)
{
	static char	*buffer = {NULL};
	char		*final_str;
	char		*aux;

	if (end == 1)
		return (ft_get_memory_liberator(&buffer));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_get_memory_liberator(&buffer));
	if (buffer == NULL || (buffer != NULL
			&& ft_get_strchr((const char *)buffer, '\n') == NULL))
		buffer = ft_read(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	aux = ft_get_strchr((const char *)buffer, '\n');
	final_str = ft_get_substr((const char *)buffer, 0, aux - buffer + 1);
	if (final_str == NULL)
		return (ft_get_memory_liberator(&buffer));
	buffer = ft_refresh(buffer, aux);
	return (final_str);
}
