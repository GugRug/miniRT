#include "minirt.h"

void	print_scene_elem(t_image *img, t_scene *scene)
{
	t_elem *lst_pointer;

	lst_pointer = scene->elem;
	// draw_background(img,scene->color_background);
	while(lst_pointer)
	{
		draw_square(img, lst_pointer);
		lst_pointer = lst_pointer->next;
	}
}
