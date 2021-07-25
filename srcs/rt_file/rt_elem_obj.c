#include "minirt.h"

void	set_rt_sphere(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 4)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	elem->sphere.center = set_rt_point(splitted[1]);
	if (!valid_float(splitted[2]))
		message_and_exit(E_CHAR_ARG, "Sphere diiameter Float only");
	elem->sphere.diameter = ft_atof(splitted[2]);
	elem->sphere.color = set_rt_color(splitted[3]);
}

void	set_rt_plane(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 4)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	elem->plane.point = set_rt_point(splitted[1]);
	elem->plane.normal = set_rt_point(splitted[2]);
	if (!validate_unit_range(elem->plane.normal.x,
		elem->plane.normal.y, elem->plane.normal.z))
		message_and_exit(E_RANGE_ARG, "Plane Normal ratio in range [-1,1]");
	elem->plane.color = set_rt_color(splitted[3]);
}

void	set_rt_square(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 5)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	elem->square.center = set_rt_point(splitted[1]);
	elem->square.normal = set_rt_point(splitted[2]);
	if (!validate_unit_range(elem->square.normal.x,
		elem->square.normal.y, elem->square.normal.z))
		message_and_exit(E_RANGE_ARG, "Square Normal ratio in range [-1,1]");
	if (!valid_float(splitted[3]))
		message_and_exit(E_CHAR_ARG, "Square side Float only");
	elem->square.side = ft_atof(splitted[3]);
	elem->square.color = set_rt_color(splitted[4]);
	set_square_vertex(&(elem->square));
}

void	set_rt_cylinder(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 6)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	elem->cylinder.center = set_rt_point(splitted[1]);
	elem->cylinder.normal = set_rt_point(splitted[2]);
	if (!validate_unit_range(elem->cylinder.normal.x,
		elem->cylinder.normal.y, elem->cylinder.normal.z))
		message_and_exit(E_RANGE_ARG, "Cylinder Normal ratio in range [-1,1]");
	elem->cylinder.normal = v_norm(elem->cylinder.normal);
	if (!valid_float(splitted[3]))
		message_and_exit(E_CHAR_ARG, "Cylinder Diameter Float only");
	elem->cylinder.diameter = ft_atof(splitted[3]);
	if (!valid_float(splitted[4]))
		message_and_exit(E_CHAR_ARG, "Cylinder Height Float only");
	elem->cylinder.height = ft_atof(splitted[4]);
	elem->cylinder.color = set_rt_color(splitted[5]);
}

void	set_rt_triangle(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 5)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	elem->triangle.vertex[0] = set_rt_point(splitted[1]);
	elem->triangle.vertex[1] = set_rt_point(splitted[2]);
	elem->triangle.vertex[2] = set_rt_point(splitted[3]);
	elem->triangle.color = set_rt_color(splitted[4]);
	elem->triangle.normal = v_norm(v_cross(
				v_sub(elem->triangle.vertex[1], elem->triangle.vertex[0]),
				v_sub(elem->triangle.vertex[2], elem->triangle.vertex[0])));
}
