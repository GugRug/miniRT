#include "minirt.h"

void	free_array(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int	free_all(t_world *w)
{
	if (w->window->win)
	{
		mlx_clear_window(w->window->mlx, w->window->win);
		mlx_destroy_window(w->window->mlx, w->window->win);
	}
	mlx_destroy_image(w->window->mlx, w->image->img);
	lst_elem_clear(&(w->window->rt->scene->elem));
	lst_elem_clear(&(w->window->rt->scene->light));
	w->window->rt->scene->camera->prev->next = NULL;
	lst_elem_clear(&(w->window->rt->scene->camera));
	exit(EXIT_SUCCESS);
	return (0);
}
