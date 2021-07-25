#include "minirt.h"

void	set_rt_resolution(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 3)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	if (!valid_int(splitted[1]) || !valid_int(splitted[2]))
		message_and_exit(E_CHAR_ARG, "Resolution Numerical only");
	elem->res.x = ft_atoi(splitted[1]);
	elem->res.y = ft_atoi(splitted[2]);
	if (!validate_posit(elem->res.x, elem->res.y, 1))
		message_and_exit(E_CHAR_ARG, "Resolution Positive Numerical only");
	elem->res.declared = true;
}

void	set_rt_ambient_lightining(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 3)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	if (!valid_float(splitted[1]))
		message_and_exit(E_CHAR_ARG, "Amb_light ratio Float only");
	elem->amb_light.amb_light = ft_atof(splitted[1]);
	if (!validate_posit(elem->amb_light.amb_light, 1, 1)
		|| !validate_unit_range(elem->amb_light.amb_light, 0.5, 0.5))
		message_and_exit(E_RANGE_ARG, "Amb_light ratio in range [0,1]");
	elem->amb_light.color = set_rt_color(splitted[2]);
	elem->amb_light.declared = true;
}

void	set_rt_camera(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 4)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	elem->camera.orig = set_rt_point(splitted[1]);
	elem->camera.normal = set_rt_point(splitted[2]);
	if (!validate_unit_range(elem->camera.normal.x,
			elem->camera.normal.y, elem->camera.normal.z))
		message_and_exit(E_RANGE_ARG, "Camera Normal ratio in range [-1,1]");
	if (!valid_int(splitted[3]))
		message_and_exit(E_CHAR_ARG, "Camera fov ratio bad CHAR detected");
	elem->camera.fov = ft_atoi(splitted[3]);
	if (!(elem->camera.fov >= 0) || !(elem->camera.fov <= 180))
		message_and_exit(E_RANGE_ARG, "Camera fov ratio in range [0,180]");
}

void	set_rt_light(t_elem *elem, char **splitted)
{
	if (strarray_len(splitted) != 4)
		message_and_exit(E_N_ARGS_FILE, splitted[0]);
	elem->light.l_p = set_rt_point(splitted[1]);
	if (!valid_float(splitted[2]))
		message_and_exit(E_CHAR_ARG, "Light ratio Float only");
	elem->light.brightness = ft_atof(splitted[2]);
	if (!validate_posit(elem->light.brightness, 1, 1)
		|| !validate_unit_range(elem->light.brightness, 0.5, 0.5))
		message_and_exit(E_RANGE_ARG, "Light ratio in range [0,1]");
	elem->light.color = set_rt_color(splitted[3]);
}
