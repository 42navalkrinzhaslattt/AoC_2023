#include "ft_split.c"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	check_line(char	*line)
{
	int		i;
	char	**arr;
	int		amount;
	int		set[3];

	arr = ft_split(line, " ,:;\n");
	i = 2;
	set[0] = 0;
	set[1] = 0;
	set[2] = 0;
	while (arr[i])
	{
		amount = atoi(arr[i]);
		if (strcmp(arr[i + 1], "red") == 0 && amount > set[0])
			set[0] = amount;
		if (strcmp(arr[i + 1], "green") == 0 && amount > set[1])
			set[1] = amount;
		if (strcmp(arr[i + 1], "blue") == 0 && amount > set[2])
			set[2] = amount;
		i += 2;
	}
	return (set[0] * set[1] * set[2]);
}

int main()
{
	int		fd;
	char	*line;
	int		res;
	int		i;

	fd = open("input.txt", O_RDONLY);
	line = get_next_line(fd);
	res = 0;
	i = 1;
	while (line)
	{
		res += check_line(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("%i", res);
}