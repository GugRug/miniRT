#include "minirt.h"

void	set_rt(t_rt *rt)
{
	char	*line;
	int		gnl;
	t_elem	*element;

	gnl = get_next_line(rt->fd, &line);
	clean_extra_space(line);
	while (line && gnl > 0)
	{
		element = set_rt_line_element(line);
		// if (element->type == AMBIENT_LIGHTINING)
		// 	print_test(rt->scene->amb_light.amb_light);
		gnl = get_next_line(rt->fd, &line);
		if (gnl <= 0)
			free(line);
		distrib_elem(rt->scene, element);
	}
	//resolution implement
}

void	distrib_elem(t_scene *scene, t_elem *elem)
{
	if (elem->type == CAMERA)
		lst_elem_add_back(&(scene->camera), elem);
	else if (elem->type == LIGHT)
		lst_elem_add_back(&(scene->light), elem);
	else if (elem->type == RESOLUTION ||
			elem->type == AMBIENT_LIGHTINING)
		set_unique_elements(scene, elem);
	else
		lst_elem_add_back(&(scene->elem), elem);
}

t_elem	*set_rt_line_element(char *line)
{
	int		j;
	char	**splitted;
	t_elem	*element;
	static char	*valid[9] = {"R ", "A ", "c ", "l ", "sp", "pl", "sq", "cy", "tr"};

	j = 0;
	element = NULL;
	while (valid[j] != NULL)
	{
		if (!ft_strncmp(valid[j], line, 2))
		{
			element = lst_elem_new(j);
			break;
		}
		j++;
	}
	splitted = ft_split(line, ' ');
	set_rt_element_content(element, splitted);
	free(splitted);
	return (element);
}

void	set_rt_element_content(t_elem *elem, char **splitted)
{
	if (elem->type == RESOLUTION)
		set_rt_resolution(elem, splitted);
	else if (elem->type == AMBIENT_LIGHTINING)
		set_rt_ambient_lightining(elem, splitted);
	else if (elem->type == CAMERA)
		set_rt_camera(elem, splitted);
	else if (elem->type == LIGHT)
		set_rt_light(elem, splitted);
	else if (elem->type == SPHERE)
		set_rt_sphere(elem, splitted);
	else if (elem->type == PLANE)
		set_rt_plane(elem, splitted);
	else if (elem->type == SQUARE)
		set_rt_square(elem, splitted);
	else if (elem->type == CYLINDER)
		set_rt_cylinder(elem, splitted);
	else if (elem->type == TRIANGLE)
		set_rt_triangle(elem, splitted);
}

void	clean_extra_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line)
	{
		if (line[i] == ' ' && i > 0 && line[i - 1] == ' ')
			ft_memmove(&line[i - 1], &line[i], ft_strlen(line));
		i++;
	}
}
