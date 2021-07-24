#include "minirt.h"



// static void		roots(t_ray r, t_cylinder cy, double root[2])
// {
// 	double		a;
// 	double		half_b;
// 	double		c;
// 	t_vect	v;
// 	t_vect	u;

// 	v = v_scale(cy.normal, v_dot(r.dir, cy.normal));
// 	v = v_sub(r.dir, v);
// 	u = v_scale(cy.normal, (v_dot(v_sub(r.orig, cy.center), cy.normal)));
// 	u = v_sub(v_sub(r.orig, cy.center), u);
// 	a = v_len_sqred(v);
// 	half_b = v_dot(v, u);
// 	c = v_len_sqred(u) - pow(cy.diameter / 2, 2);
// 	root[0] = (-half_b - sqrt(pow(half_b, 2) - a * c)) / a;
// 	root[1] = (-half_b + sqrt(pow(half_b, 2) - a * c)) / a;
// }

// static float	solve(t_ray r, t_cylinder cy, float *y, bool hit[2])
// {
// 	float		t;
// 	float		dist[2];
// 	float		root[2];
// 	t_vector	b_ray;

// 	roots(r, cy, root);
// 	b_ray = sub(cy.center, r.origin);
// 	dist[0] = dot(cy.axis, sub(scale(r.direction, root[0]), b_ray));
// 	dist[1] = dot(cy.axis, sub(scale(r.direction, root[1]), b_ray));
// 	hit[0] = (dist[0] >= 0 && dist[0] <= cy.height && root[0] > EPSILON);
// 	hit[1] = (dist[1] >= 0 && dist[1] <= cy.height && root[1] > EPSILON);
// 	if (hit[0] && hit[1])
// 	{
// 		*y = root[0] < root[1] ? dist[0] : dist[1];
// 		t = root[0] < root[1] ? root[0] : root[1];
// 	}
// 	else
// 	{
// 		*y = hit[0] ? dist[0] : dist[1];
// 		t = hit[0] ? root[0] : root[1];
// 	}
// 	return (t);
// }

// bool			hit_cylinder(t_ray *ray, t_cylinder *cylinder)
// {
// 	float		y;
// 	float		t;
// 	bool		hit[2];

// 	t = solve(*ray, *cylinder, &y, hit);
// 	if ((hit[0] || hit[1]) && ray->record.t > t && t > EPSILON)
// 	{
// 		ray->record.t = t;
// 		ray->record.p = at(*ray);
// 		ray->record.normal = norm(sub(ray->record.p,
// 					add(scale(cylinder->axis, y), cylinder->center)));
// 		if (hit[1] & !hit[0])
// 			ray->record.normal = scale(ray->record.normal, -1);
// 		ray->record.color = cylinder->color;
// 	}
// 	return (hit[0] || hit[1]);
// }


void	main_teste()
{
	t_ray	ray;
	ray = new_ray(new_point(1,2,3), new_point(4,5,6));

}

int		mouse_track(int button, int x, int y, t_window *window)
{
	if (button == 1)
	{
		mlx_mouse_get_pos(window->mlx, window->win, &x, &y);
		printf("Cursor coords.: %4d x %4d\n", x,
				window->rt->scene->res.y - y);
	}
	return (0);
}

void	draw_square(t_scene *scene, t_elem *sqr)
{
	//SQUARE

	int end_x, end_y;

	end_x =	sqr->square.center.x + sqr->square.side/2;
	end_y = sqr->square.center.y + sqr->square.side/2;

	int	i =	sqr->square.center.x - sqr->square.side/2;
	int	j = sqr->square.center.y - sqr->square.side/2;
	while (i < end_x)
	{
		j = sqr->square.center.y - sqr->square.side/2;
		while (j < end_y)
		{
			set_canvas_point(&(scene->canvas), i, j, sqr->square.color);
			j++;
		}
		i++;
	}
}

int	write_test(void)
{
	write(1, "---teste---\n", 12);
	return (0);
}

int	print_test(double p)
{
	printf("print_test:|%f|\n", p);
	return (0);
}
// int	render_next_frame(void *window)
// {
// 	return (0);
// }

//write(1, "teste\n", 6);
