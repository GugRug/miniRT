#include "minirt.h"

bool	hit_sphere_root(t_elem *elem, t_ray *ray, double *root)
{
	double	a;
	double	b;
	double	c;
	t_vect	d;

	d = v_sub(ray->orig, elem->sphere.center);
	a = v_dot(ray->dir, ray->dir);
	b = 2 * v_dot(ray->dir, d);
	c = v_dot(d, d) - pow((elem->sphere.diameter)/2, 2);
	if (baskara(a, b, c, root) >= 0)
		return (true);
	return (false);
}

bool	check_edge(t_vect to, t_vect from, t_vect pos, t_vect normal)
{
	t_vect	edge;
	t_vect	vec_p;

	edge = v_sub(to, from);
	vec_p = v_sub(pos, from);
	return (v_dot(normal, v_cross(edge, vec_p)) >= EPSILON);
}

bool	check_all_edges(t_elem *elem, t_ray *ray)
{
	return ((check_edge(elem->triangle.s_p, 
		elem->triangle.f_p,ray->pos, elem->triangle.normal))
		&& (check_edge(elem->triangle.t_p,
		elem->triangle.s_p,ray->pos, elem->triangle.normal))
		&& (check_edge(elem->triangle.f_p,
		elem->triangle.t_p,ray->pos, elem->triangle.normal)));
}