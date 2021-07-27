#include "minirt.h"

t_canvas	new_canvas(int width, int height)
{
	int			i;
	int			j;
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	i = -1;
	canvas.canv = (int **)malloc((width + 1) * sizeof (int **));
	canvas.canv[width] = NULL;
	while (i++ < width)
		canvas.canv[i] = (int *)malloc((height + 1) * sizeof (int *));
	i = -1;
	while (i++ < width)
	{
		j = 0;
		while (j < height)
		{
			canvas.canv[i][j] = 0;
			j++;
		}
	}
	return (canvas);
}

void	set_canvas_point(t_canvas *canvas, int x, int y, int color)
{
	if (canvas->height >= y && y >= 0
		&& canvas->width >= x && x >= 0)
	{
		canvas->canv[x][(canvas->height - 1 - y)] = color;
	}
}

void	print_canvas(t_canvas *canvas, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < canvas->width)
	{
		j = 0;
		while (j < canvas->height)
		{
			draw_pixel(img, i, j, canvas->canv[i][j]);
			j++;
		}
		i++;
	}
}

void	set_canvas(t_canvas *canvas, t_scene *scene)
{
	int		i;
	int		j;
	t_ray	ray;
	t_color	color;

	i = canvas->width;
	while (i-- > 0)
	{
		j = canvas->height;
		while (j-- > 0)
		{
			ray = start_raytrace(scene, (double)(i) / canvas->width,
					(double)(j) / canvas->height);
			color = raytrace(&ray, scene);
			set_canvas_point(&(scene->canvas), i, j, color);
		}
	}
}
