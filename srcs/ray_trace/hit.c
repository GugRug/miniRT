#include "minirt.h"

bool	*hit_sphere_root(t_elem *elem, t_ray *ray, double *root)
{
	double	a;
	double	b;
	double	c;
	t_vect	d;

	d = v_sub(ray->orig, elem->sphere.center);
	a = v_dot(ray->dir, ray->dir);
	b = 2 * v_dot(ray->dir, d);
	c = v_dot(d, d) - pow((elem->sphere.diameter)/2, 2);
	if (baskara_delta(a, b, c) >= 0)
	{
		root = baskara(a, b, c);
		return (true);
	}
	return (false);
}

void	hit_sphere(t_elem *elem,t_ray *ray)
{
	int		i;
	double	*root;

	i = 0;
	if (!hit_sphere_root(elem, ray, root))
		return;
	while (i < 2)
	{
		if (ray->t > root[i] && root[i] > 0)
		{
			ray->intersect = true;
			ray->t = root[i];
			ray->norm = v_norm(ray->dir);
			ray_position(ray);
		}
		i++;
	}
}

void	hit_plane(t_elem *elem,t_ray *ray)
{

}

void	hit_square(t_elem *elem,t_ray *ray)
{

}

void	hit_cylinder(t_elem *elem,t_ray *ray)
{

}

void	hit_triangle(t_elem *elem,t_ray *ray)
{

}
