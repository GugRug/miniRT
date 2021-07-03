#include "minirt.h"

void	set_rt_resolution(t_elem *elem, char **splitted)
{
	//was declared already?
	elem->x = atoi(splitted[1]);
	elem->y = atoi(splitted[2]);
}

void	set_rt_ambient_lightining(t_elem *elem, char **splitted)
{
	//was declared already?
	// double amb_lgh;

	// amb_lgh = atof(splitted[1]);
	// if (amb_lgh >= 0 && amb_lgh <= 1)
	// 	elem->ambient_light = amb_lgh;
	// set ratio scope error later with else
	elem->ambient_light = atof(splitted[1]);
	set_rt_color(elem, splitted[2]);
}

void	set_rt_camera(t_elem *elem, char **splitted)
{
	elem->v_p = set_rt_point(splitted[1]);
	elem->orient_vect = set_rt_point(splitted[2]);
	elem->fov = atoi(splitted[3]);
}

void	set_rt_light(t_elem *elem, char **splitted)
{
	elem->l_p = set_rt_point(splitted[1]);
	elem->light_brightness = atof(splitted[2]);
	set_rt_color(elem, splitted[3]);
}

void	set_rt_sphere(t_elem *elem, char **splitted)
{
	elem->center = set_rt_point(splitted[1]);
	elem->diameter = atof(splitted[2]);
	set_rt_color(elem, splitted[3]);
}

void	set_rt_plane(t_elem *elem, char **splitted)
{
	elem->f_p = set_rt_point(splitted[1]);
	elem->orient_vect = set_rt_point(splitted[2]);
	set_rt_color(elem, splitted[3]);
}

void	set_rt_square(t_elem *elem, char **splitted)
{
	elem->center = set_rt_point(splitted[1]);
	elem->orient_vect = set_rt_point(splitted[2]);
	elem->side = ft_atof(splitted[3]);
	set_rt_color(elem, splitted[4]);
}

void	set_rt_cylinder(t_elem *elem, char **splitted)
{
	elem->center = set_rt_point(splitted[1]);
	elem->orient_vect = set_rt_point(splitted[2]);
	elem->diameter = atof(splitted[3]);
	elem->height = atof(splitted[4]);
	set_rt_color(elem, splitted[5]);
}

void	set_rt_triangle(t_elem *elem, char **splitted)
{
	elem->f_p = set_rt_point(splitted[1]);
	elem->s_p = set_rt_point(splitted[2]);
	elem->t_p = set_rt_point(splitted[3]);
	set_rt_color(elem, splitted[4]);
}
