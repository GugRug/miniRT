#include "minirt.h"

void	validate_args(int argc, char **argv, t_rt *rt)
{
	if (argc < 1 || argc > 3)
		message_and_exit(E_N_ARGS, NULL);
	if (!argv || !*argv)
		message_and_exit(E_N_ARGS, NULL);
	if (!validate_rt_name(argv[1]))
		message_and_exit(E_C_ARGS, NULL);
	rt->fd = open(argv[1], O_RDONLY);
	if ((rt->fd) < 0)
		message_and_exit(E_FILE, NULL);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		rt->save = true;
	else
		rt->save = false;
	set_rt(rt);
}

void	set_unique_elements(t_scene *scene, t_elem *elem)
{
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

	char	*ext;
	ext = ft_strrchr(name, '.');
	if (ext && !ft_strncmp(ext, ".rt", 4))
		return (true);
	return (false);
}
