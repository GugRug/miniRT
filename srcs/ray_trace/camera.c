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
		camera->orient_vect = v_norm(camera->orient_vect);
		camera->orient_vect = v_scale(camera->orient_vect, -1);
		w = v_norm(camera->orient_vect);
		u = v_cross(new_point(0, 1, 0), w);
		v = v_cross(w, u);
		camera->hor = v_scale(u, camera->fov);
	//	print_test(u.x);
		camera->ver = v_scale(v, (camera->fov) * ratio);
		camera->llc = v_sub(camera->orig, v_scale(camera->hor, 0.5));
		camera->llc = v_sub(camera->llc, v_scale(camera->ver, 0.5));
		camera->llc = v_sub(camera->llc, w);
		cam = cam->next;
	}
}
