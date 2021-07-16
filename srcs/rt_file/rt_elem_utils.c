#include "minirt.h"

double	ft_atof(const char *str)
{
	char	**splitted;

	double	n1;
	double	n2;
	splitted = ft_split(str, '.');
	n1 = (double)(ft_atoi(splitted[0]));
	n2 = 0;
	if (splitted[1])
		n2 = ft_atoi(splitted[1])/pow(10, ft_strlen(splitted[1]));
	free(splitted);
	return (n1 + n2);
}

t_coord	set_rt_point(char *str)
{
	t_coord	point;
	char	**splitted;

	splitted = ft_split(str, ',');
	point = new_point(ft_atof(splitted[0]),
						ft_atof(splitted[1]),
						ft_atof(splitted[2]));
	free(splitted);
	splitted = NULL;
	return (point);
}

int		set_rt_color(char *str)
{
	char	**splitted;
	int		color;

	splitted = ft_split(str, ',');
	color = color_conv(ft_atoi(splitted[0]),
						ft_atoi(splitted[1]),
						ft_atoi(splitted[2]));
	free(splitted);
	splitted = NULL;
	return (color);
}
