#include "minirt.h"

void	set_rt_sphere(t_elem *elem, char **splitted)
{
	elem->sphere.center = set_rt_point(splitted[1]);
	elem->sphere.diameter = ft_atof(splitted[2]);
	elem->sphere.color = set_rt_color(splitted[3]);
}

void	set_rt_plane(t_elem *elem, char **splitted)
{
	elem->plane.point = set_rt_point(splitted[1]);
	elem->plane.normal = set_rt_point(splitted[2]);
	elem->plane.color = set_rt_color(splitted[3]);
}

void	set_rt_square(t_elem *elem, char **splitted)
{
	elem->square.center = set_rt_point(splitted[1]);
	elem->square.normal = set_rt_point(splitted[2]);
	elem->square.side = ft_atof(splitted[3]);
	elem->square.color = set_rt_color(splitted[4]);
	set_square_vertex(&(elem->square));
}

void	set_rt_cylinder(t_elem *elem, char **splitted)
{
	elem->cylinder.center = set_rt_point(splitted[1]);
	elem->cylinder.normal = set_rt_point(splitted[2]);
	elem->cylinder.diameter = ft_atof(splitted[3]);
	elem->cylinder.height = ft_atof(splitted[4]);
	elem->cylinder.color = set_rt_color(splitted[5]);
}

void	set_rt_triangle(t_elem *elem, char **splitted)
{
	elem->triangle.vertex[0] = set_rt_point(splitted[1]);
	elem->triangle.vertex[1] = set_rt_point(splitted[2]);
	elem->triangle.vertex[2] = set_rt_point(splitted[3]);
	elem->triangle.color = set_rt_color(splitted[4]);
	elem->triangle.normal = v_norm(v_cross(
					v_sub(elem->triangle.vertex[1], elem->triangle.vertex[0]), 
					v_sub(elem->triangle.vertex[2], elem->triangle.vertex[0])));
}
