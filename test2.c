#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*extract_rest(char *str)
{
	int		i;
	char	*rest;
	int		len;
	int		j;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\n' || str[i + 1] == '\0')
		return (free(str), NULL);
	len = ft_strlen(str) - i - 1;
	rest = malloc(len + 1);
	// if (rest == NULL)
	// 	return (free(str), NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		rest[j++] = str[i++];
	rest[j] = '\0';
	return (rest);
}

int main()
{
	char str[] = "asH\nell";
	char *x = extract_rest(str);
	printf("%s", x);
	return 0;
}