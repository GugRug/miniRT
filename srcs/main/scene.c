#include "minirt.h"

void	print_scene_elem(t_image *img, t_scene *scene)
{
	t_elem *lst_pointer;

	lst_pointer = scene->elem;
	// draw_background(img,scene->color_background);
	while(lst_pointer)
	{
		select_scene_elem(img, lst_pointer);
		lst_pointer = lst_pointer->next;
	}
}

void	select_scene_elem(t_image *img, t_elem *elem)
{
		if (elem->type == SQUARE)
			draw_square(img, elem);
}
