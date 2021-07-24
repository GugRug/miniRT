#include "minirt.h"

bool	hit_sphere(t_elem *elem,t_ray *ray)
{
	int		i;
	double	root[2];
	bool	hit;

	i = 0;
	hit = false;
	if (!hit_sphere_root(elem, ray, root))
		return (hit);
	while (i < 2)
	{
		if (ray->t > root[i] && root[i] > 0)
		{
			ray->color = elem->sphere.color;
			ray->t = root[i];
			ray_position(ray);
			ray->normal = v_norm(v_sub(ray->pos, elem->sphere.center));
			hit = true;
		}
		i++;
	}
	return (hit);
}

bool	hit_plane(t_elem *elem,t_ray *ray)
{
	double	t;
	double	den;

	den = v_dot(v_norm(ray->dir), elem->plane.normal);
	if (!den)
		return (false);
	t = v_dot(v_sub(elem->plane.point, ray->orig), elem->plane.normal) / den;
	if (ray->t > t && t > 0)
	{
		ray->color = elem->plane.color;
		ray->t = t;
		if (v_dot(ray->dir, elem->plane.normal) > 0)
			elem->plane.normal = v_scale(elem->plane.normal, -1);
		ray_position(ray);
		ray->normal = elem->plane.normal;
		return (true);
	}
	return (false);
}

bool	hit_square(t_elem *elem,t_ray *ray)
{
	t_elem	temp_plane;
	t_ray	temp_ray;

	double	border;


	temp_plane.plane.point = elem->square.center;
	temp_plane.plane.normal = elem->square.normal;
	temp_plane.plane.color = elem->square.color;
	temp_ray.orig = ray->orig;
	temp_ray.dir = ray->dir;
	temp_ray.t = ray->t;
	border = elem->square.side / 2;
	if (hit_plane(&temp_plane, &temp_ray)
		&& is_inside(temp_ray, elem->square.vertex, 4))
	{
		ray->color = elem->square.color;
		ray->normal = elem->square.normal;
		ray->t = temp_ray.t;
		ray_position(ray);
		return (true);
	}
	return (false);


}

bool	hit_cylinder(t_elem *elem,t_ray *ray)
{
	bool		ret[2];
	double		time;
	double		y;

	time = cy_calc(*ray, *elem, &y, ret);
	if ((ret[0] || ret[1]) && ray->t > time && time > EPSILON)
	{
		ray->t = time;
		ray_position(ray);
		ray->normal = v_norm(v_sub(ray->pos,
				v_add(v_scale(elem->cylinder.normal, y), elem->cylinder.center)));
		if (ret[0] == false & ret[1] == true)
			ray->normal = v_scale(ray->normal, -1);
		ray->color = elem->cylinder.color;
	}
	return (ret[0] || ret[1]);
}

bool	hit_triangle(t_elem *elem,t_ray *ray)
{
	t_elem	temp_plane;
	t_ray	temp_ray;

	temp_plane.plane.point = elem->triangle.vertex[0];
	temp_plane.plane.normal = elem->triangle.normal;
	temp_plane.plane.color = elem->triangle.color;
	temp_ray.orig = ray->orig;
	temp_ray.dir = ray->dir;
	temp_ray.t = ray->t;
	if (hit_plane(&temp_plane, &temp_ray)
		&& is_inside(temp_ray, elem->triangle.vertex, 3))
	{
		ray->color = elem->triangle.color;
		ray->normal = elem->triangle.normal;
		ray->t = temp_ray.t;
		ray_position(ray);
		return (true);
	}
	return (false);
}
