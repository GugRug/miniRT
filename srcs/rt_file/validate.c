#include "minirt.h"

void	validate_args(int argc, char **argv, t_rt *rt)
{
	if (argc < 1 || argc > 3)
		message_and_exit(E_N_ARGS, NULL);
	if (!argv || !*argv)
		message_and_exit(E_N_ARGS, NULL);
	validate_rt_name(argv[1]);
	if((rt->fd = open(argv[1], O_RDONLY)) < 0)
		message_and_exit(E_FILE, NULL);
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
		free(elem);
		elem = NULL;
		if (scene->res.declared == true)
			message_and_exit(E_R_A_FILE, NULL);
		scene->res.declared = true;
	}
	else if (elem->type == AMBIENT_LIGHTINING)
	{
		lst_elem_cut(elem);
		scene->amb_light.amb_light = elem->amb_light.amb_light;
		scene->amb_light.color = elem->amb_light.color;
		free(elem);
		elem = NULL;
		if (scene->amb_light.declared == true)
			message_and_exit(E_R_A_FILE, NULL);
		scene->amb_light.declared = true;
	}
}

bool	validate_rt_name(char *name)
{
	if(!name)
		return (false);
	// if (ft_strncmp(name, ".rt", 3) != 0)
	// 	message_and_exit(E_C_ARGS, NULL);
	return (true);
}
