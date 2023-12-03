#include "ft_split.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int	ft_atoi_rewrite(char *nptr)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
		nptr--;
	nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		nptr[i] = '.';
		i++;
	}
	return (res);
}

int	count_digits_around(char **arr, int i, int k)
{
	int	counter;

	counter = 0;
	if (isdigit(arr[i - 1][k - 1]))
		counter++;
	if (isdigit(arr[i - 1][k]))
		counter++;
	if (isdigit(arr[i - 1][k + 1]))
		counter++;
	if (isdigit(arr[i][k - 1]))
		counter++;
	if (isdigit(arr[i + 1][k - 1]))
		counter++;
	if (isdigit(arr[i + 1][k]))
		counter++;
	if (isdigit(arr[i][k + 1]))
		counter++;
	if (isdigit(arr[i + 1][k + 1]))
		counter++;
	if (isdigit(arr[i + 1][k + 1]) && isdigit(arr[i + 1][k]) && isdigit(arr[i + 1][k - 1]))
		counter -=2;
	if (!isdigit(arr[i + 1][k + 1]) && isdigit(arr[i + 1][k]) && isdigit(arr[i + 1][k - 1]))
		counter --;
	if (isdigit(arr[i + 1][k + 1]) && isdigit(arr[i + 1][k]) && !isdigit(arr[i + 1][k - 1]))
		counter --;
	if (isdigit(arr[i - 1][k + 1]) && isdigit(arr[i - 1][k]) && isdigit(arr[i - 1][k - 1]))
		counter -=2;
	if (!isdigit(arr[i - 1][k + 1]) && isdigit(arr[i - 1][k]) && isdigit(arr[i - 1][k - 1]))
		counter --;
	if (isdigit(arr[i - 1][k + 1]) && isdigit(arr[i - 1][k]) && !isdigit(arr[i - 1][k - 1]))
		counter--;
	return (counter);
}

int	get_value_multi(char **arr, int i)
{
	int	j;
	int	a;
	int	b;
	int	res;
	int	multi;

	j = 0;
	res = 0;
	while (arr[i][j])
	{
		if (arr[i][j] == '*')
		{
			if (count_digits_around(arr, i, j) == 2)
			{
				a = -1;
				multi = 1;
				while (a <= 1)
				{
					b = -1;
					while (b <= 1)
					{
						if (isdigit(arr[i + a][j + b]))
							multi *= ft_atoi_rewrite(&(arr[i + a][j + b]));
						b++;
					}
					a++;
				}
				res += multi;
			}
		}
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

	fd = open("day_03_2/input.txt", O_RDONLY);
	bzero(buf, 1000000);
	read(fd, buf, 1000000);
	arr = ft_split(buf, "\n");
	res = 0;
	i = 1;
	while (arr[i])
	{
		res += get_value_multi(arr, i);
		i++;
	}
	printf("%i", res);
}
