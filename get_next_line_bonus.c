/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:59:20 by asmounci          #+#    #+#             */
/*   Updated: 2025/11/09 16:28:51 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	static char	*rest[MAX_FD];
	char		*line;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	while (bytes_read > 0 && ft_strchr(rest[fd], '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(rest[fd]), free(buffer), rest[fd] = NULL, NULL);
		buffer[bytes_read] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buffer);
	}
	line = extract_line(rest[fd]);
	rest[fd] = extract_rest(rest[fd]);
	free(buffer);
	return (line);
}
