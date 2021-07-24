#include "minirt.h"

t_color	raytrace(t_ray *ray, t_scene *scene)
{
	t_color	color;
	t_color comp_color;
	t_color	amb;
	t_elem	*lgt;
	t_light	*light;

	lgt = scene->light;
	amb = color_scale(scene->amb_light.color,
						scene->amb_light.amb_light);
	if (!(ray->intersect))
		return (0);
	color = color_product(ray->color, amb);
	while (lgt)
	{
		light = &(lgt->light);
		if (!light_intersect(ray, light, scene, &comp_color))
			color = color_add(color, comp_color);
		lgt = lgt->next;
	}
	return (color);
}

bool	light_intersect(t_ray *ray, t_light *light, t_scene *scene, t_color *color)
{
	t_ray	light_ray;
	t_vect	reflect_ray;
	double	r2;
	double	gain;
	double	brightness;

	*color = 0;
	light_ray.orig = v_add(ray->pos, v_scale(ray->normal, EPSILON));
	light_ray.dir = v_norm(v_sub(light->l_p, light_ray.orig));
	intersect(&light_ray, scene);
	if(!light_ray.intersect)
	{
		reflect_ray = v_sub(light->l_p,ray->pos);
		r2 = v_len_sqred(reflect_ray);
		gain = v_dot(v_norm(reflect_ray), ray->normal);
		if (gain < 0)
			gain = 0;
		gain *= 1000;
		brightness = (light->brightness * gain) /
							(4.0 * FT_M_PI * r2);
		*color = color_product(color_scale(ray->color, brightness),
							light->color);
	}
	return (light_ray.intersect);
}

void	intersect(t_ray *ray, t_scene *scene)
{
	t_elem	*elem;
	bool	hit;
	elem = scene->elem;

	ray->t = INFINITY;
	hit = false;
	while (elem)
	{
		if (elem->type == SPHERE)
			hit |= hit_sphere(elem, ray);
		else if (elem->type == PLANE)
			hit |= hit_plane(elem, ray);
		else if (elem->type == SQUARE)
			hit |= hit_square(elem, ray);
		else if (elem->type == TRIANGLE)
			hit |= hit_triangle(elem, ray);
		else if (elem->type == CYLINDER)
			hit |= hit_cylinder(elem, ray);
		elem = elem->next;
	}
	ray->intersect = hit;
}

t_ray	start_raytrace(t_scene *scene, double u, double v)
{
	t_vect	hor;
	t_vect	ver;
	t_vect	llc;
	t_ray	ray;

	hor = scene->camera->camera.hor;
	ver = scene->camera->camera.ver;
	llc = scene->camera->camera.llc;

	ray.orig = scene->camera->camera.orig;
	ray.dir = v_add(v_scale(hor, u), v_scale(ver, v));
	ray.dir = v_add(ray.dir, llc);
	ray.dir = v_norm(v_sub(ray.dir, ray.orig));
	ray.root = 0;
	ray.t = INFINITY;
	ray.intersect = false;
	ray.color = 0;
	intersect(&ray, scene);
	return (ray);
}
