/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:42:41 by asmounci          #+#    #+#             */
/*   Updated: 2025/11/08 22:07:19 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char*			buffer = malloc(BUFFER_SIZE + 1);
	ssize_t			bytes_read = 1;
	static char*	rest;
	char *line;
	
	while (bytes_read > 0 && ft_strchr(rest, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
			return NULL;
		buffer[bytes_read] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	line = extract_line(rest);
	rest = extract_rest(rest);
	free(buffer);
	return line;
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *s = get_next_line(fd);
	while(s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
}