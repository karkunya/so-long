#include "unistd.h"
#include "stdlib.h"
#include <stdio.h>
#include <fcntl.h>

void malloc_util(char **argv, int *col, int *cos)
{
	int fd;
	int rd[2];
	int rs;

	fd = open((argv[1]), O_RDONLY);
	rs = 1;
	while (rs > 0)
	{
		rs = read(fd, rd, 1);
		if (rs == -1)
			exit(1);
		if (rd[0] == '\n')
			(*col)++;
		else if ((*col) == 1)
			(*cos)++;
	}
	return ;
}

int main(int argc, char **argv)
{
	int col = 1;
	int cos = 0;
	char **map;

	malloc_util(argv, &col, &cos);
	map = malloc(sizeof(*char) * (col + 1));
	map[col] = 0;
	map[col] = malloc(sizeof(char) * (cos + 1));
	while (col--)
		map[col] = malloc(sizeof(char) * (cos + 1));
	printf("%d\n %d\n", col, cos);
}
