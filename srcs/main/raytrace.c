#include "minirt.h"

t_color	raytrace(t_ray *ray, t_scene *scene)
{
	t_color	color;
	t_color	amb;

	amb = color_scale(scene->amb_light.color,
						scene->amb_light.amb_light);
	while (scene->light)
	{

	}
}
bool	*hit_sphere_root(t_elem *elem, t_ray *ray, double *root)
{
	double	a;
	double	b;
	double	c;
	t_vect	d;

	d = v_sub(ray->orig, elem->sphere.center);
	a = v_dot(ray->pos, ray->pos);
	b = 2 * v_dot(ray->pos, d);
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
