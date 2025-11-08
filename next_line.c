#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


char *next_line(int fd)
{
	char buffer[2];
	char *line = NULL;
	buffer[1] = '\0';
	while (read(fd, buffer, 1) > 0 && buffer[0] != '\n')
		line = ft_strjoin(line, buffer);
	if (buffer[0] == '\n')
		line = ft_strjoin(line, buffer);
	return line;
}


int main()
{
	int fd = open("file.txt", O_RDONLY);
   
	char *x = next_line(fd);
	printf("%s", x);
	x = next_line(fd);
	printf("%s", x);
	x = next_line(fd);
	printf("%s", x);
	x = next_line(fd);
	printf("%s", x);
	x = next_line(fd);
	printf("%s", x);
	x = next_line(fd);
	printf("%s", x);
	// while(x)
	// {
	// 	x = next_line(fd);
	// }
}