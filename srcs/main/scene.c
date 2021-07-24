#include "minirt.h"

void	print_scene_elem(t_image *img, t_scene *scene)
{
	// t_elem	*lst_pointer;

	// lst_pointer = scene->elem;
	// while(lst_pointer)
	// {
	// 	select_scene_elem(scene, lst_pointer);
	// 	lst_pointer = lst_pointer->next;
	// }
	init_camera(&(scene->camera->camera), scene);
	set_canvas(&(scene->canvas), scene);
	print_canvas(&(scene->canvas), img);
}

// void	select_scene_elem(t_scene *scene, t_elem *elem)
// {
// 		if (elem->type == SQUARE)
// 			draw_square(scene, elem);
// }
