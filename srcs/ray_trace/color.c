#include "minirt.h"

t_color	color_conv(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int		get_red(t_color rgb)
{
	return (rgb & (0xFF << 16));
}

int		get_green(t_color rgb)
{
	return (rgb & (0xFF << 8));
}

int		get_blue(t_color rgb)
{
	return (rgb & 0xFF);
}

int		color_check(int color)
{
	if (color > 0xFF)
		return (0xFF);
	else if(color < 0x0)
		return (0x0);
	return (color);
}

t_color	color_add(t_color u, t_color v)
{
	int 	red;
	int 	green;
	int 	blue;

	red = (get_red(u) + get_red(v)) & (0xFF << 16);
	green = (get_green(u) + get_green(v)) & (0xFF << 8);
	blue = (get_blue(u) + get_blue(v)) & (0xFF);
	return (red | green | blue);
}

t_color	color_scale(t_color rgb, double c)
{
	int 	red;
	int 	green;
	int 	blue;

	red = (int)(get_red(rgb) * c) & (0xFF << 16);
	green = (int)(get_green(rgb) * c) & (0xFF << 8);
	blue = (int)(get_blue(rgb) * c) & (0xFF);
	return (red | green | blue);
}

t_color	color_product(t_color u, t_color v)
{
	int		r;
	int		g;
	int		b;

	r = (((float)(u >> 0x10) / 0xFF) *
			((float)(v >> 0x10) / 0xFF)) * 0xFF;
	g = (((float)((u >> 0x08) & 0xFF) / 0xFF) *
			((float)((v >> 0x08) & 0xFF) / 0xFF)) * 0xFF;
	b = (((float)(u & 0xFF) / 0xFF) *
			((float)(v & 0xFF) / 0xFF)) * 0xFF;
	return ((r << 16) | (g << 8) | b);
}
