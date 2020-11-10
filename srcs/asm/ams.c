#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		printf("Usage error\n");
	else
		printf("conver champion %s\n", av[1]);
	return (0);
}
