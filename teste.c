#include <stdio.h>

int	main()
{
	char	*str;
	char	*temp;

	str = "abcdefghij\n";
	temp = &str[5];
	printf("%s", temp);
	temp = &str[2];
	printf("%s", temp);
}