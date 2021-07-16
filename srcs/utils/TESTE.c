#include "minirt.h"

void	main_teste()
{
	t_ray	ray;
	ray = new_ray(build_point(1,2,3), build_point(4,5,6));
	
}

void	draw_square(t_scene *scene, t_elem *sqr)
{
	//SQUARE

	int end_x, end_y;

	end_x =	sqr->square.center.x + sqr->square.side/2;
	end_y = sqr->square.center.y + sqr->square.side/2;

	int	i =	sqr->square.center.x - sqr->square.side/2;
	int	j = sqr->square.center.y - sqr->square.side/2;
	while (i < end_x)
	{
		j = sqr->square.center.y - sqr->square.side/2;
		while (j < end_y)
		{
			set_canvas_point(&(scene->canvas), i, j, sqr->square.color);
			j++;
		}
		i++;
	}
}

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
