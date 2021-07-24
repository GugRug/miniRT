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
	if (bhaskara(a, b, c, root) >= 0)
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

double	cy_calc(t_ray ray, t_elem cy, double *y, bool ret[2])
{
	t_coord	v[2];
	t_coord	v_cy2ray;
	double	time[2];
	double	dist[2];

	v[0] = v_sub(ray.dir, v_scale(cy.cylinder.normal, v_dot(ray.dir, cy.cylinder.normal)));
	v[1] = v_sub(v_sub(ray.orig, cy.cylinder.center),
			v_scale(cy.cylinder.normal, v_dot(v_sub(ray.orig, cy.cylinder.center), cy.cylinder.normal)));
	bhaskara(v_len_sqred(v[0]), 2 * v_dot(v[0], v[1]),
				v_len_sqred(v[1]) - pow(cy.cylinder.diameter / 2, 2), time);
	v_cy2ray = v_sub(cy.cylinder.center, ray.orig);
	dist[0] = v_dot(cy.cylinder.normal, v_sub(v_scale(ray.dir, time[0]), v_cy2ray));
	dist[1] = v_dot(cy.cylinder.normal, v_sub(v_scale(ray.dir, time[1]), v_cy2ray));
	ret[0] = (dist[0] >= 0 && dist[0] <= cy.cylinder.height && time[0] > EPSILON);
	ret[1] = (dist[1] >= 0 && dist[1] <= cy.cylinder.height && time[1] > EPSILON);
	if (!ret[0] && ret[1])
	{
		*y = dist[1];
		return (time[1]);
	}
	*y = dist[0];
	return (time[0]);
}
