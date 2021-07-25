#include "minirt.h"

int		clamp(int x)
{
	if (x > 0xFF)
		return (0xFF);
	else if (x < 0)
		return (0);
	return (x);
}

t_color	color_conv(int red, int green, int blue)
{
	if (red > 255 || green > 255 || blue > 255
		|| red < 0 || green < 0 || blue < 0)
		message_and_exit(E_RANGE_ARG, "Color Range [0,255]");
	return (red << 16 | green << 8 | blue);
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

	red = clamp((u >> 0x10) + (v >> 0x10));
	green = clamp((u >> 0x08 & 0xFF) + (v >> 0x08 & 0xFF));
	blue = clamp((u & 0xFF) + (v & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

t_color	color_scale(t_color rgb, double c)
{
	int 	red;
	int 	green;
	int 	blue;

	red = clamp(c * (rgb >> 0x10));
	green = clamp(c * ((rgb >> 0x08) & 0xFF));
	blue = clamp(c * (rgb & 0xFF));
	return ((red << 16) | (green << 8) | blue);
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
