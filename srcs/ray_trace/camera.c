#include "minirt.h"

void	init_camera(t_camera *camera, t_scene *scene)
{
	t_vect	u;
	t_vect	v;
	t_vect	w;
	double	ratio;
	t_elem	*cam;

	cam = scene->camera;
	while (cam)
	{
		camera = &(cam->camera);
		ratio = ((double)(scene->res.y) /scene->res.x);
		camera->fov = 2 * tan((camera->fov * (FT_M_PI / 180)) / 2);
		camera->normal = v_norm(camera->normal);
		camera->normal = v_scale(camera->normal, -1);
		w = v_norm(camera->normal);
		u = v_cross(new_point(0, 1, 0), w);
		v = v_cross(w, u);
		camera->hor = v_scale(u, camera->fov);
		camera->ver = v_scale(v, (camera->fov) * ratio);
		camera->llc = v_sub(camera->orig, v_scale(camera->hor, 0.5));
		camera->llc = v_sub(camera->llc, v_scale(camera->ver, 0.5));
		camera->llc = v_sub(camera->llc, w);
		cam = cam->next;
		if (cam == scene->camera)
			break;
	}
}

void	change_camera(int keycode, t_world *w)
{
	if (keycode == KEY_A)
		w->window->rt->scene->camera = w->window->rt->scene->camera->prev;
	if (keycode == KEY_D)
		w->window->rt->scene->camera = w->window->rt->scene->camera->next;
	print_scene_elem(w->image, w->window->rt);
	mlx_put_image_to_window(w->window->mlx, w->window->win,
									w->image->img, 0, 0);
}
