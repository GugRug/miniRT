#include "minirt.h"

void	print_scene_elem(t_image *img, t_rt *rt)
{
	set_canvas(&(rt->scene->canvas), rt->scene);
	print_canvas(&(rt->scene->canvas), img);
	if (rt->save)
		export_bitmap("bitmap.bmp", img->width, img->height, *img);
}
