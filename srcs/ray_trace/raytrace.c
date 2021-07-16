#include "minirt.h"

t_color	raytrace(t_ray *ray, t_scene *scene)
{
	t_color	color;
	t_color	amb;
	t_elem	*lgt;
	t_light	*light;

	lgt = scene->light;
	amb = color_scale(scene->amb_light.color,
						scene->amb_light.amb_light);
	if (!(ray->intersect))
		return (0);
	color = ray->color;
	color = color_product(color, amb);
	while (lgt)
	{
		light = &(lgt->light);
		light->color = color_scale(light->color,
									light->brightness);
		color = color_product(color, light->color);
		light->intersect = light_intersect(ray, light, scene); //create a ray going from l_p instead of camera, call the intersect funct


		lgt = lgt->next;
	}
}

bool	light_intersect(t_ray *ray, t_light *light, t_scene *scene)
{
	t_ray	light_ray; //ray - l_p ?
}

void	intersect(t_ray *ray, t_scene *scene)
{
	t_elem	*elem;

	elem = scene->elem;
	while (elem)
	{
		if (elem->type == SPHERE)
			hit_sphere(elem, ray);
		else if (elem->type == PLANE)
			hit_plane(elem, ray);
		else if (elem->type == SQUARE)
			hit_square(elem, ray);
		else if (elem->type == CYLINDER)
			hit_cylinder(elem, ray);
		else if (elem->type == TRIANGLE)
			hit_triangle(elem, ray);
		elem = elem->next;
	}
}

void	start_raytrace(t_ray *ray, t_scene *scene, double u, double v)
{
	t_vect	hor;
	t_vect	ver;
	t_vect	llc;

	hor = scene->camera->camera.hor;
	ver = scene->camera->camera.ver;
	llc = scene->camera->camera.llc;
	ray->orig = scene->camera->camera.orig;
	ray->dir = v_add(v_scale(hor, u), v_scale(ver, v));
	ray->dir = v_add(ray->dir, llc);
	ray->dir = v_norm(v_sub(ray->dir, ray->orig));
	ray->pos = ray->dir;
	intersect(ray, scene);
}
