#include "minirt.h"

t_ray	new_ray(t_coord orig, t_vect dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	ray.pos = dir;
	ray.root = 0;
	ray.t = INFINITY;
	ray.intersect = false;
	ray.color = 0;
	return (ray);
}

double	baskara_delta(double a, double b, double c)
{
	double	delta;

	delta = b*b - 4*a*c;
	return (delta);
}

double	*baskara(double a, double b, double c)
{
	double	delta;
	double	root[2];

	delta = b*b - 4*a*c;
	root[0] = ((-1)*b - sqrt(delta)) / (2*a);
	root[1] = ((-1)*b + sqrt(delta)) / (2*a);
	return (root);
}

void	ray_position(t_ray *ray)
{
	ray->pos = v_add(ray->orig, v_scale(ray->dir, ray->t));
}
