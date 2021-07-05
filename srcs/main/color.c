#include "minirt.h"

int	conv_color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_red(int rgb)
{
	return (rgb & (0xFF << 16));
}

int	get_green(int rgb)
{
	return (rgb & (0xFF << 8));
}

int	get_blue(int rgb)
{
	return (rgb & 0xFF);
}

int	add_shade(double shade, int rgb)
{
	int red;
	int green;
	int blue;
	red = (int)(get_red(rgb) * shade) & (0xFF << 16);
	green = (int)(get_green(rgb) * shade) & (0xFF << 8);
	blue = (int)(get_blue(rgb) * shade) & (0xFF);
	return (red | green | blue);
}
