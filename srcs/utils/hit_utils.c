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

bool	is_inside(t_ray r, t_coord *v, unsigned int vertex)
{
	unsigned int	i;
	bool			in;
	float			det[vertex];
	t_vect			det_cross;

	in = true;
	i = 0;
	while (i < vertex)
	{
		if (i == vertex - 1)
			det_cross = v_cross(v_sub(v[i], v[0]), v_sub(r.pos, v[0]));
		else
			det_cross = v_cross(v_sub(v[i], v[i + 1]), v_sub(r.pos, v[i + 1]));
		det[i] = v_dot(det_cross, r.normal);
		if (i > 0)
			in &= (det[i - 1] >= 0) ^ (det[i] < 0);
		i++;
	}
	return (in);
}

// bool	check_edge(t_vect to, t_vect from, t_vect pos, t_vect normal)
// {
// 	t_vect	edge;
// 	t_vect	vec_p;
// 	bool check;

// 	edge = v_sub(to, from);
// 	vec_p = v_sub(pos, from);
// 	check = (v_dot(normal, v_cross(edge, vec_p)) >= EPSILON);
// 	return (check);
// }

// bool	check_all_edges(t_elem *elem, t_ray *ray)
// {
// 	bool	check;

// 	check = ((check_edge(elem->triangle.vertex[1], 
// 		elem->triangle.vertex[0],ray->pos, elem->triangle.normal))
// 		&& (check_edge(elem->triangle.vertex[2],
// 		elem->triangle.vertex[1],ray->pos, elem->triangle.normal))
// 		&& (check_edge(elem->triangle.vertex[0],
// 		elem->triangle.vertex[2],ray->pos, elem->triangle.normal)));
// 	return (check);
// }