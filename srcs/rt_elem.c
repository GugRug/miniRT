#include "minirt.h"

double	ft_atof(const char *str)
{
	char	**splitted;

	double	n1;
	double	n2;

	splitted = ft_split(str, '.');
	n1 = (double)(ft_atoi(splitted[0]));
	n2 = ft_atoi(splitted[1])/(10 * ft_strlen(splitted[1]));
	free(splitted);
	return (n1 + n2);
}

void	set_rt_square(t_elem *elem, char **splitted)
{
	set_rt_center(elem, splitted[1]);
	set_rt_orient_vect(elem, splitted[2]);
	set_rt_side(elem, splitted[3]);
	set_rt_color(elem, splitted[4]);
}
// void	set_rt_square(t_elem *elem, char **splitted)
// {

// }
