#include "minirt.h"

void	set_rt_center(t_elem *elem, char *str)
{
	char	**splitted;
	//t_coord	center;

	splitted = ft_split(str, ',');
//	elem->center = &center;
	elem->center->x = ft_atof(splitted[0]);
	elem->center->y = ft_atof(splitted[1]);
	elem->center->z = ft_atof(splitted[2]);
	free(splitted);
}

void	set_rt_orient_vect(t_elem *elem, char *str)
{
	char	**splitted;
	//t_coord	orient_vect;

	splitted = ft_split(str, ',');
	//elem->orient_vect = &orient_vect;
	elem->orient_vect->x = ft_atof(splitted[0]);
	elem->orient_vect->y = ft_atof(splitted[1]);
	elem->orient_vect->z = ft_atof(splitted[2]);
	free(splitted);
}

void	set_rt_side(t_elem *elem, char *str)
{
	elem->side = ft_atof(str);
}

void	set_rt_color(t_elem *elem, char *str)
{
	char	**splitted;

	splitted = ft_split(str, ',');
	elem->color = conv_color(ft_atoi(splitted[0]),
							ft_atoi(splitted[1]),
							ft_atoi(splitted[2]));
	free(splitted);
}
