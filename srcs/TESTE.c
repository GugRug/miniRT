#include "minirt.h"


void	draw_test(t_image *img, int side, int cen_x, int cen_y, int color)
{
	//SQUARE

	int end_x, end_y;

	end_x =	cen_x + side/2;
	end_y = cen_y + side/2;

	int	i =	cen_x - side/2;
	int	j = cen_y - side/2;

	while (i < end_x)
	{
		j = cen_y - side/2;
		while (j < end_y)
		{
			draw_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}
