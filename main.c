#include "libprintf.h"
#include <stdio.h>

int 	main(int argc, char **argv)
{
	(void)argc;
	ft_printf(*++argv, 42, -42);
	printf("@\n");
	printf(*argv, 42, -42);
	printf("@\n");
	return (1);
}
