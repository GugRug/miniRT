#include "minirt.h"

int		key_hook(int keycode, t_world *w)
{
	if (keycode == KEY_ESC)
		free_all(w);
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
	mlx_hook(x->win, 33, 1L << 17, free_all, world);
	mlx_key_hook(x->win, key_hook, world);
	mlx_mouse_hook(x->win, mouse_track, x);
	mlx_expose_hook(x->win, expose_hook, world);
	mlx_loop(x->mlx);
	return (0);
}
