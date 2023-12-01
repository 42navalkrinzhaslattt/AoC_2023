#include "./ft_get_next_line/get_next_line.c"
#include "./ft_get_next_line/get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>

int	get_value(char *line)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			res += 10 * (line[i] - 48);
			break;
		}
		i++;
	}
	i = gnl_strlen(line, 0) - 1;
	while (i >= 0)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			res += line[i] - 48;
			break;
		}
		i--;
	}
	return (res);
}

int	main()
{
	int		fd;
	char	*line;
	int		res;

	fd = open ("input.txt", O_RDONLY);
	line = get_next_line(fd);
	res = 0;
	while (line)
	{
		res += get_value(line);
		free(line);
		line = get_next_line(fd);
	}
	printf("%i", res);
	return (0);
}
