#include "minirt.h"

double	ft_atof(const char *str)
{
	char	**splitted;
	double	n1;
	double	n2;
	int		signal;
	splitted = ft_split(str, '.');
	signal = 1;
	if(*splitted && **splitted == '-')
		signal = -1;
	n1 = (double)(ft_atoi(splitted[0]));
	n2 = 0;
	if (splitted[1])
		n2 = ft_atoi(splitted[1])/pow(10, ft_strlen(splitted[1]));
	free(splitted);
	if ((n1 + n2) > 0)
		return ((n1 + n2) * signal);
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

void	set_square_vertex(t_square *s)
{
	t_vect		i;
	t_vect		j;

	i = v_cross(s->normal, new_point(s->normal.z, s->normal.x, s->normal.y));
	j = v_cross(s->normal, i);
	i = v_scale(i, s->side / 2);
	j = v_scale(j, s->side / 2);
	s->vertex[0] = v_add(v_add(s->center, i), j);
	s->vertex[1] = v_sub(v_add(s->center, i), j);
	s->vertex[2] = v_sub(v_sub(s->center, i), j);
	s->vertex[3] = v_add(v_sub(s->center, i), j);
}