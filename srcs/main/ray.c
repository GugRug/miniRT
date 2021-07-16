#include "minirt.h"

t_ray	new_ray(t_coord orig, t_vect dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	ray.pos = dir;
	ray.root = 0;
	ray.t = 1;
	ray.intersect = false;
	ray.color = 0;
	return (ray);
}

void	shot_ray(t_scene *scene)
{
	scene->ray.intersect = intersect(scene, &(scene->ray));
}


bool	intersect(t_scene *scene, t_ray *ray)
{
	double	delta;
	bool	hit;
	t_elem	*elem;

	ray->t = INFINITY;
	hit = false;
	elem = scene->elem;
	while (elem)
	{
	if (elem->type == SPHERE)
		hit |= hit_sphere(elem, ray);
	else if (elem->type == PLANE)
		hit |= hit_plane(elem, ray);
	else if (elem->type == SQUARE)
		hit |= hit_square(elem, ray);
	else if (elem->type == CYLINDER)
		hit |= hit_cylinder(elem, ray);
	else if (elem->type == TRIANGLE)
		hit |= hit_triangle(elem, ray);
	elem = elem->next;
	}
	return (false);
}

double	baskara_delta(double a, double b, double c)
{
	double	delta;

	delta = b*b - 4*a*c;
	return (delta);
}

double	*baskara(double a, double b, double delta)
{
	double	root[2];

	root[0] = ((-1)*b - sqrt(delta)) / (2*a);
	root[1] = ((-1)*b + sqrt(delta)) / (2*a);
	return (root);
}

void	ray_position(t_ray *ray)
{
	ray->pos = v_add(ray->orig, v_scale(ray->dir, ray->t));
}
