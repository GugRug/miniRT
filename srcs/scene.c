#include "minirt.h"

#define TEST_SCENE_BACKGROUND_COLOR 0xff0000
#define TEST_SCENE_SQUARE_COLOR 0x00ff00
#define TEST_SCENE_SQUARE_SIDE 50
#define TEST_SCENE_SQUARE_CENTER_X 400
#define TEST_SCENE_SQUARE_CENTER_Y 400
#define TEST2_SCENE_SQUARE_COLOR 0x0000ff
#define TEST2_SCENE_SQUARE_SIDE 80
#define TEST2_SCENE_SQUARE_CENTER_X 800
#define TEST2_SCENE_SQUARE_CENTER_Y 800

void	get_scene_elem(t_scene *scene)
{
	t_elem *new_elem;
	t_elem *ptr_elem;

	new_elem = lst_elem_new(SQUARE);
	scene->elem = lst_elem_new(SQUARE);
	ptr_elem = scene->elem;
	scene->color_background = TEST_SCENE_BACKGROUND_COLOR;

	scene->elem->color = TEST_SCENE_SQUARE_COLOR;
	scene->elem->side = TEST_SCENE_SQUARE_SIDE;
	scene->elem->center->x = TEST_SCENE_SQUARE_CENTER_Y;
	scene->elem->center->y = TEST_SCENE_SQUARE_CENTER_Y;

	new_elem->color = TEST2_SCENE_SQUARE_COLOR;
	new_elem->side = TEST2_SCENE_SQUARE_SIDE;
	new_elem->center->x = TEST2_SCENE_SQUARE_CENTER_Y;
	new_elem->center->y = TEST2_SCENE_SQUARE_CENTER_Y;
	lst_elem_add_back(&ptr_elem, new_elem);
}

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
