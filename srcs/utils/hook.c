#include "minirt.h"

int	key_hook(int keycode, t_window *window)
{
	// printf("\nKeycode: %x\n---\n", keycode);
	if (keycode == KEY_ESC)
		destroy_window(window);
	return (1);
}

int	destroy_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	window->win = NULL;
	exit(1);
	return (0);
}
