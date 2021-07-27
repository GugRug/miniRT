#include "minirt.h"

int	main(int argc, char **argv)
{
	t_world		world;
	t_window	window;
	t_image		image;
	t_rt		rt;
	t_scene		scene;

	world.window = &window;
	world.image = &image;
	set_init(&window, &rt, &scene);
	validate_args(argc, argv, window.rt);
	set_init_mlx(&window, &image);
	init_camera(&(window.rt->scene->camera->camera), &scene);
	print_scene_elem(&image, window.rt);
	if (rt.save)
		free_all(&world);
	call_hook(&world);
	return (0);
}

void	set_init(t_window *window, t_rt *rt, t_scene *scene)
{
	window->win = NULL;
	window->rt = rt;
	window->rt->scene = scene;
	window->rt->scene->elem = NULL;
	window->rt->scene->camera = NULL;
	window->rt->scene->light = NULL;
	window->rt->scene->res.declared = false;
	window->rt->scene->amb_light.declared = false;
	window->title = "miniRT";
}

void	set_init_mlx(t_window *window, t_image *image)
{
	window->mlx = mlx_init();
	if (!(window->mlx))
		message_and_exit(E_SYS, NULL);
	mlx_get_screen_size(window->mlx, &(window->rt->width),
		&(window->rt->height));
	if (window->rt->scene->res.x > window->rt->width)
		window->rt->scene->res.x = window->rt->width;
	if (window->rt->scene->res.y > window->rt->height)
		window->rt->scene->res.y = window->rt->height;
	window->width = window->rt->scene->res.x;
	window->height = window->rt->scene->res.y;
	if (!window->rt->save)
		window->win = mlx_new_window(window->mlx, window->width,
				window->height, window->title);
	if (!(window->win))
		message_and_exit(E_SYS, NULL);
	image->width = window->rt->scene->res.x;
	image->height = window->rt->scene->res.y;
	window->rt->scene->canvas = new_canvas(window->width, window->height);
	image->img = mlx_new_image(window->mlx, image->width, image->height);
	if (!(image->img))
		message_and_exit(E_SYS, NULL);
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel),
			&(image->line_length), &(image->endian));
}
