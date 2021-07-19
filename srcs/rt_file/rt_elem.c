#include "minirt.h"

void	set_rt_resolution(t_elem *elem, char **splitted)
{
	//was declared already?
	elem->res.x = atoi(splitted[1]);
	elem->res.y = atoi(splitted[2]);
	elem->res.declared = true;
}

void	set_rt_ambient_lightining(t_elem *elem, char **splitted)
{
	//was declared already?
	// double amb_lgh;

	// amb_lgh = atof(splitted[1]);
	// if (amb_lgh >= 0 && amb_lgh <= 1)
	// 	elem->ambient_light = amb_lgh;
	// set ratio scope error later with else
	elem->amb_light.amb_light = ft_atof(splitted[1]);
	elem->amb_light.color = set_rt_color(splitted[2]);
	elem->amb_light.declared = true;
}

void	set_rt_camera(t_elem *elem, char **splitted)
{
	elem->camera.orig = set_rt_point(splitted[1]);
	elem->camera.orient_vect = set_rt_point(splitted[2]);
	elem->camera.fov = atoi(splitted[3]);
}

void	set_rt_light(t_elem *elem, char **splitted)
{
	elem->light.l_p = set_rt_point(splitted[1]);
	elem->light.brightness = ft_atof(splitted[2]);
	elem->light.color = set_rt_color(splitted[3]);
}

void	set_rt_sphere(t_elem *elem, char **splitted)
{
	elem->sphere.center = set_rt_point(splitted[1]);
	elem->sphere.diameter = ft_atof(splitted[2]);
	elem->sphere.color = set_rt_color(splitted[3]);
}

void	set_rt_plane(t_elem *elem, char **splitted)
{
	elem->plane.f_p = set_rt_point(splitted[1]);
	elem->plane.orient_vect = set_rt_point(splitted[2]);
	elem->plane.color = set_rt_color(splitted[3]);
}

void	set_rt_square(t_elem *elem, char **splitted)
{
	elem->square.center = set_rt_point(splitted[1]);
	elem->square.orient_vect = set_rt_point(splitted[2]);
	elem->square.side = ft_atof(splitted[3]);
	elem->square.color = set_rt_color(splitted[4]);
}

void	set_rt_cylinder(t_elem *elem, char **splitted)
{
	elem->cylinder.center = set_rt_point(splitted[1]);
	elem->cylinder.orient_vect = set_rt_point(splitted[2]);
	elem->cylinder.diameter = ft_atof(splitted[3]);
	elem->cylinder.height = ft_atof(splitted[4]);
	elem->cylinder.color = set_rt_color(splitted[5]);
}


void	set_rt_triangle(t_elem *elem, char **splitted)
{
	elem->triangle.f_p = set_rt_point(splitted[1]);
	elem->triangle.s_p = set_rt_point(splitted[2]);
	elem->triangle.t_p = set_rt_point(splitted[3]);
	elem->triangle.color = set_rt_color(splitted[4]);
}
