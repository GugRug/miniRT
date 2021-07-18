#include "minirt.h"

void	validate_args(int argc, char **argv, t_rt *rt)
{
	if (argc < 1 || argc > 3)
		return;
	if (!argv || !*argv)
		return;
	if (validate_rt_name(argv[1]))
		rt->fd = open(argv[1], O_RDONLY);
	else
		return;
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		rt->save = true;
	else
		rt->save = false;
	set_rt(rt);
	// set_unique_elements(&rt);
}

void	set_unique_elements(t_scene *scene, t_elem *elem)
{
	// if((elem->type == RESOLUTION && scene->res.declared == true) ||
	// (elem->type == AMBIENT_LIGHTINING &&
	// scene->amb_light.declared == true))
	// 	return; //need error here
	// else
	if (elem->type == RESOLUTION)
	{
		lst_elem_cut(elem);
		scene->res.x = elem->res.x;
		scene->res.y = elem->res.y;
		scene->res.declared = true;
		//delete elem
		free(elem);
		elem = NULL;
	}
	else if (elem->type == AMBIENT_LIGHTINING)
	{
		lst_elem_cut(elem);
		scene->amb_light.amb_light = elem->amb_light.amb_light;
		scene->amb_light.color = elem->amb_light.color;
		scene->amb_light.declared = true;
		free(elem);
		elem = NULL;
		//delete elem
	}
}

bool	validate_rt_name(char *name)
{
	if (name)	//need to test if is *.rt later
		return (true);
	return (false);
}
