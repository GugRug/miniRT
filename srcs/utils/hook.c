#include "minirt.h"

int		key_hook(int keycode, t_world *w)
{
	if (keycode == KEY_ESC)
		destroy_window(w->window);
	if ((keycode == KEY_A) || (keycode == KEY_D))
		change_camera(keycode, w);
	return (1);
}

int		destroy_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	window->win = NULL;
	exit(1);
	return (0);
}

int		expose_hook(t_world *w)
{
	return(mlx_put_image_to_window(w->window->mlx, w->window->win,
									w->image->img, 0, 0));
}

int		call_hook(t_world *world)
{
	t_window *x;

	x = (world->window);

	mlx_hook(x->win, 33, 1L << 17, destroy_window, x);
	mlx_key_hook(x->win, key_hook, world);
	mlx_mouse_hook(x->win, mouse_track, x);
	// mlx_hook(x->win, 2, 1L << 0, key_hook, x);
	// mlx_hook(x->win, 4, 1L << 2, print_test, x);
	mlx_expose_hook(x->win, expose_hook, world);
	mlx_loop(x->mlx);
	// mlx_put_image_to_window(world->ptr,
	// 		world->window, world->image, 0, 0);
	// mlx_expose_hook(world->window->win, expose_hook, world);
	// mlx_loop(x->mlx);
	return (0);
}
