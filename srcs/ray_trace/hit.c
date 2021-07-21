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

void	hit_sphere(t_elem *elem,t_ray *ray)
{
	int		i;
	double	root[2];

	i = 0;
	if (!hit_sphere_root(elem, ray, root))
		return;
	while (i < 2)
	{
		if (ray->t > root[i] && root[i] > 0)
		{
			ray->color = elem->sphere.color;
			ray->intersect = true;
			ray->t = root[i];
			ray_position(ray);
			ray->normal = v_norm(v_sub(ray->pos, elem->sphere.center));
		}
		i++;
	}
}

void	hit_plane(t_elem *elem,t_ray *ray)
{
	double	t;
	double	den;

	den = v_dot(v_norm(ray->dir), elem->plane.orient_vect);
	if (!den)
		return;
	t = v_dot(v_sub(elem->plane.f_p, ray->orig), elem->plane.orient_vect) / den;
	if (ray->t > t && t > 0)
	{
		ray->color = elem->plane.color;
		ray->intersect = true;
		ray->t = t;
		if (v_dot(ray->dir, elem->plane.orient_vect) > 0)
			elem->plane.orient_vect = v_scale(elem->plane.orient_vect, -1);
		ray_position(ray);
		ray->normal = elem->plane.orient_vect;
	}
}

void	hit_square(t_elem *elem,t_ray *ray)
{
	
}

// void	hit_cylinder(t_elem *elem,t_ray *ray)
// {

// }

// void	hit_triangle(t_elem *elem,t_ray *ray)
// {

// }
