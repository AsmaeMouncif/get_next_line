#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char    *extract_line(char *str)
{
    int        i;
    int        j;
    char    *line;

    if (str == NULL || str[0] == '\0')
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        line = malloc(i + 2);
    else
        line = malloc(i + 1);
    if (line == NULL)
        return (NULL);
    j = 0;
    while (j < i)
    {
        line[j] = str[j];
        j++;
    }
    if (str[i] == '\n')
        line[j++] = '\n';
    line[j] = '\0';
    return (line);
}

#include <stdio.h>

int main() {
    char str[] = "0123456789\n012345678";
    char *s = extract_line(str);
    printf("%s",s);
    return 0;
}