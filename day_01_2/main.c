#include "./ft_get_next_line/get_next_line.c"
#include "./ft_get_next_line/get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	digitwrd_cmp(char *str, char *digits[9])
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (strstr(str, digits[i]) == str)
			return (i + 1);
		i++;
	}
	return (0);
}

int	get_value(char *line, char *digits[9])
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || digitwrd_cmp(line + i, digits))
		{
			if (line[i] >= '0' && line[i] <= '9')
				res += 10 * (line[i] - 48);
			else
				res += 10 * (digitwrd_cmp(line + i, digits));
			break;
		}
		i++;
	}
	i = gnl_strlen(line, 0) - 1;
	while (i >= 0)
	{
		if ((line[i] >= '0' && line[i] <= '9') || digitwrd_cmp(line + i, digits))
		{
			if (line[i] >= '0' && line[i] <= '9')
				res += line[i] - 48;
			else
				res += digitwrd_cmp(line + i, digits);
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
	char	*digits[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	fd = open ("day_01_2/input.txt", O_RDONLY);
	line = get_next_line(fd);
	res = 0;
	while (line)
	{
		res += get_value(line, digits);
		free(line);
		line = get_next_line(fd);
	}
	printf("%i", res);
	return (0);
}
