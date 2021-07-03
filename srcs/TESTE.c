#include "minirt.h"



int	write_test(void)
{
	write(1, "---teste---\n", 12);
	return (0);
}

int	print_test(int p)
{
	printf("print_test:|%d|\n", p);
	return (0);
}
// int	render_next_frame(void *window)
// {
// 	return (0);
// }

//write(1, "teste\n", 6);
