#include "ft_split.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int	is_char(char c)
{
	if (isdigit(c) || c == '.' || c == 0)
		return (0);
	return (1);
}

int	get_value(char **arr, int i)
{
	int	j;
	int	k;
	int	res;
	int	flag;

	j = 0;
	res = 0;
	while (arr[i][j])
	{
		if (arr[i][j] >= '0' && arr[i][j] <= '9')
		{
			k = j;
			flag = 0;
			while (arr[i][k] >= '0' && arr[i][k] <= '9')
			{
				if (is_char(arr[i - 1][k - 1]) || is_char(arr[i - 1][k]) || is_char(arr[i][k - 1]) || is_char(arr[i + 1][k - 1])
					|| is_char(arr[i + 1][k]) || is_char(arr[i - 1][k + 1]) || is_char(arr[i][k + 1]) || is_char(arr[i + 1][k + 1]))
					flag = 1;
				k++;
			}
			if (flag == 1)
				res += atoi(arr[i] + j);
			j = k;
		}
		else
			j++;
	}
	return (res);
}

int main()
{
	int fd;
	char buf[1000000];
	char **arr;
	int res;
	int i;

	fd = open("day_03_1/input.txt", O_RDONLY);
	bzero(buf, 1000000);
	read(fd, buf, 1000000);
	arr = ft_split(buf, "\n");
	res = 0;
	i = 1;
	while (arr[i])
	{
		res += get_value(arr, i);
		i++;
	}
	printf("%i", res);
}
