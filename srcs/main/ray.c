#include "minirt.h"

t_ray	new_ray(t_vect dir)
{
	t_ray	ray;

	ray.orig = build_point(0, 0, 0);
	ray.dir = dir;
	ray.color = 0;

	return (ray);
}
