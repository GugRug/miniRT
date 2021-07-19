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
	color = color_product(ray->color, amb);
	while (lgt)
	{
	// if (color > 0)
	// 	printf("Color: |%x|\n", color);
		light = &(lgt->light);
		// printf("Color: |%x|\n", lgt->light.color);
		light->color = color_scale(light->color,
									light->brightness);
		if (light_intercept(ray, light, scene))
		{
			printf("Color before: |%x|\n", color);
			color = color_add(color, light->color);
			printf("------ Light intersect is true! ------\n");
			printf("Color after: |%x|\n", color);
		}
		lgt = lgt->next;
	}
	return (color);
}

bool	light_intercept(t_ray *ray, t_light *light, t_scene *scene)
{
	t_ray	light_ray;
	double	r2;
	double	gain;

	// light_ray.dir = v_sub(ray->dir, light->l_p);
	light_ray.orig = v_add(ray->pos, v_scale(ray->normal, EPSILON));
	light_ray.dir = v_norm(v_sub(light->l_p, light_ray.orig));
	intersect(&light_ray, scene);
	if(!light_ray.intersect)
	{
		printf("------ Light intersect is true! ------\n");
		light_ray.norm = v_norm(light_ray.dir);
		r2 = v_len_sqred(light_ray.norm);
		gain = v_dot(light_ray.norm, ray->normal);
		if (gain < 0)
			gain = 0;
		gain *= 1000;
		light->brightness = (light->brightness * gain) /
							(4.0 * FT_M_PI * r2);
		light->color = color_product(color_scale(ray->color,
						light->brightness), light->color);
	}
	return (light_ray.intersect);
}

void	intersect(t_ray *ray, t_scene *scene)
{
	t_elem	*elem;

	elem = scene->elem;
	while (elem)
	{
		if (elem->type == SPHERE)
			hit_sphere(elem, ray);
		// else if (elem->type == PLANE)
		// 	hit_plane(elem, ray);
		// else if (elem->type == SQUARE)
		// 	hit_square(elem, ray);
		// else if (elem->type == CYLINDER)
		// 	hit_cylinder(elem, ray);
		// else if (elem->type == TRIANGLE)
		// 	hit_triangle(elem, ray);
		elem = elem->next;
	}
	// if ((ray->intersect))
	// 	ray_position(ray);
	//print_test(42);
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
