/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:42:41 by asmounci          #+#    #+#             */
/*   Updated: 2025/11/09 13:59:51 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	static char	*rest;
	char		*line;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes_read > 0 && ft_strchr(rest, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(rest), rest = NULL, NULL);
		buffer[bytes_read] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	line = extract_line(rest);
	rest = extract_rest(rest);
	free(buffer);
	return (line);
}
