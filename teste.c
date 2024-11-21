#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	char	*str = "text_01";
	int		fd2;

	fd1 = open(str, O_RDONLY);
	fd2 = open("text_02", O_RDONLY);
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
	close(fd1);
	close(fd2);
}