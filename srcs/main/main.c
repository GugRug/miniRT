#include "minirt.h"

int main(int argc, char **argv)
{
	t_window	window;
	t_image		image;
	t_rt		rt;
	t_scene		scene;

	set_init(&window, &rt, &scene);
	validate_args(argc, argv, window.rt);
	set_init_mlx(&window, &image);

	print_scene_elem(&image, window.rt->scene);
	//main_test();
	mlx_put_image_to_window(window.mlx, window.win, image.img, 0, 0);

	//mlx_hook(window.win, 4, 1L << 2, print_test, &window);
	mlx_hook(window.win, 33, 1L << 17, destroy_window, &window);
	mlx_key_hook(window.win, key_hook, &window);
	//mlx_loop_hook(window.mlx, render_next_frame, &window);
	mlx_loop(window.mlx);
	return (0);
}

void	set_init(t_window *window, t_rt *rt, t_scene *scene)
{
	window->rt = rt;
	window->rt->scene = scene;
	window->rt->scene->elem = NULL;
	window->rt->scene->camera = NULL;
	window->rt->scene->light = NULL;
	window->rt->scene->res.declared = false;
	window->rt->scene->amb_light.declared = false;
	window->title = "ABACATE";
}

void	set_init_mlx(t_window *window, t_image *image)
{
	window->width = window->rt->scene->res.x;
	window->height = window->rt->scene->res.y;
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width, window->height, window->title);
	image->width = window->rt->scene->res.x;
	image->height = window->rt->scene->res.y;
	window->rt->scene->canvas = new_canvas(window->width, window->height);
	image->img = mlx_new_image(window->mlx, image->width, image->height);
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel),
	&(image->line_length), &(image->endian));
	mlx_put_image_to_window(window->mlx, window->win, image->img, 0, 0);
}
