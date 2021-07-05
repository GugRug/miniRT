#include "minirt.h"

void	draw_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_background(t_image *img, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= img->height)
	{
		while (x <= img->width)
		{
			draw_pixel(img, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}
