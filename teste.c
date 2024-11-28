#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	char	*str1 = "text_01";
	int		fd2;
	char	*str2 = "text_02";

	fd1 = open(str1, O_RDONLY);
	fd2 = open(str2, O_RDONLY);
	if (fd1 == -1)
	{
		write(2, "File not found\n", 15);
		return (0);
	}
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	close(fd1);
	close(fd2);
}